/******************************************************************************
 * updated: 4-5-2012  
 * Project:  OpenCPN
 * Purpose:  test Plugin
 * Author:   David Register
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */


#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers
#include <wx/stdpaths.h>
#include <wx/timer.h>
#include <wx/event.h>
#include <wx/sysopt.h>
#include <wx/dir.h>
#include <wx/stdpaths.h>
#include <wx/filefn.h>
#include <wx/msgdlg.h>
#include <wx/listbook.h>
#include <wx/panel.h>

#include <wx/aui/aui.h>

#include "testplugin_pi.h"
#include "version.h"
#include "wxWTranslateCatalog.h"

#include "ODAPI.h"
#include "tpJSON.h"
#include "tpicons.h"
#include "tpControlDialogImpl.h"

#include "wx/jsonwriter.h"


//#include "pluginmanager.h"

#ifndef DECL_EXP
#ifdef __WXMSW__
#define DECL_EXP     __declspec(dllexport)
#else
#define DECL_EXP
#endif
#endif

#if !defined(NAN)
static const long long lNaN = 0xfff8000000000000;
#define NAN (*(double*)&lNaN)
#endif

testplugin_pi           *g_testplugin_pi;
//PlugInManager           *g_tp_pi_manager;
wxString                *g_PrivateDataDir;

wxString                *g_pHome_Locn;
wxString                *g_pData;
wxString                *g_SData_Locn;
wxString                *g_pLayerDir;

PlugIn_ViewPort         *g_pVP;
PlugIn_ViewPort         g_VP;
wxString                *g_tplocale;
void                    *g_ppimgr;

tpJSON                  *g_ptpJSON;
ODAPI                   *g_ptpAPI;
double                  g_dVar;
int                     g_iLocaleDepth;
wxString                *g_tpLocale;

wxFont                  *g_pFontTitle;
wxFont                  *g_pFontData;
wxFont                  *g_pFontLabel;
wxFont                  *g_pFontSmall;

wxString                g_ReceivedODAPIMessage;
wxJSONValue             g_ReceivedODAPIJSONMsg;


// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new testplugin_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}


//---------------------------------------------------------------------------------------------------------
//
//    testplugin PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

testplugin_pi::testplugin_pi(void *ppimgr)
:opencpn_plugin_113(ppimgr)
{
    // Create the PlugIn icons
    g_ppimgr = ppimgr;
//    g_tp_pi_manager = (PlugInManager *) ppimgr;
    g_testplugin_pi = this;
    
    wxString *l_pDir = new wxString(*GetpPrivateApplicationDataLocation());
    appendOSDirSlash( l_pDir );
    l_pDir->Append(_T("plugins"));
    appendOSDirSlash( l_pDir );
    if ( !wxDir::Exists(*l_pDir))
        wxMkdir( *l_pDir );
    l_pDir->Append(_T("testplugin_pi"));
    appendOSDirSlash( l_pDir );
    if ( !wxDir::Exists(*l_pDir))
        wxMkdir( *l_pDir );
    g_PrivateDataDir = new wxString;
    g_PrivateDataDir->Append(*l_pDir);
    g_pData = new wxString(*l_pDir);
    g_pData->append( wxS("data") );
    appendOSDirSlash( g_pData );
    if ( !wxDir::Exists(*g_pData))
        wxMkdir( *g_pData );
    g_pLayerDir = new wxString;
    g_pLayerDir->Append(*l_pDir);
    g_pLayerDir->Append( wxT("Layers") );
    appendOSDirSlash( g_pLayerDir );
    
    m_ptpicons = new tpicons();
    
    delete l_pDir;
}

testplugin_pi::~testplugin_pi()
{
    delete g_SData_Locn;
    g_SData_Locn = NULL;
    
    delete g_PrivateDataDir;
    g_PrivateDataDir = NULL;
    
    delete g_pData;
    g_pData = NULL;
    
    delete g_pLayerDir;
    g_pLayerDir = NULL;
    
}

int testplugin_pi::Init(void)
{
    g_tplocale = NULL;
    m_btpDialog = false;
    m_tpControlDialogImpl = NULL;
    m_cursor_lat = 0.0;
    m_cursor_lon = 0.0;
    m_click_lat = 0.0;
    m_click_lon = 0.0;
    
    // Adds local language support for the plugin to OCPN
    AddLocaleCatalog( PLUGIN_CATALOG_NAME );
    
    eventsEnabled = true;
    
    // Get a pointer to the opencpn display canvas, to use as a parent for windows created
    m_parent_window = GetOCPNCanvasWindow();
    
    m_tpControlDialogImpl = new tpControlDialogImpl(m_parent_window);
    m_tpControlDialogImpl->Fit();
    m_tpControlDialogImpl->Layout();
    m_tpControlDialogImpl->Hide();
    
    g_ptpJSON = new tpJSON;
    
    
#ifdef TESTPLUGIN_USE_SVG
    m_testplugin_button_id  = InsertPlugInToolSVG(_("Test Plugin"), m_ptpicons->m_s_testplugin_grey_pi, m_ptpicons->m_s_testplugin_pi, m_ptpicons->m_s_testplugin_toggled_pi, wxITEM_CHECK,
                                                  _("Test Plugin"), wxS(""), NULL, testplugin_POSITION, 0, this);
#else
    m_testplugin_button_id  = InsertPlugInTool(_("Test Plugin"), &m_ptpicons->m_bm_testplugin_grey_pi, &m_ptpicons->m_bm_testplugin_pi, wxITEM_CHECK,
                                             _("Test Plugin"), wxS(""), NULL, testplugin_POSITION, 0, this);
#endif
    
    //    In order to avoid an ASSERT on msw debug builds,
    //    we need to create a dummy menu to act as a surrogate parent of the created MenuItems
    //    The Items will be re-parented when added to the real context meenu
    wxMenu dummy_menu;
    
    // Create an OCPN Draw event handler
    //g_WVEventHandler = new WVEventHandler( g_testplugin_pi );
    
    // Get item into font list in options/user interface
    AddPersistentFontKey( wxT("tp_Label") );
    AddPersistentFontKey( wxT("tp_Data") );
    g_pFontTitle = GetOCPNScaledFont_PlugIn( wxS("tp_Title") );
    g_pFontLabel = GetOCPNScaledFont_PlugIn( wxS("tp_Label") );
    g_pFontData = GetOCPNScaledFont_PlugIn( wxS("tp_Data") );
    g_pFontSmall = GetOCPNScaledFont_PlugIn( wxS("tp_Small") );
    wxColour l_fontcolour = GetFontColour_PlugIn( wxS("tp_Label") );
    l_fontcolour = GetFontColour_PlugIn( wxS("tp_Data") );
    
    m_pOD_FindPointInAnyBoundary = NULL;
    m_pODFindClosestBoundaryLineCrossing = NULL;
    
    return (
        WANTS_CURSOR_LATLON       |
        WANTS_TOOLBAR_CALLBACK    |
        INSTALLS_TOOLBAR_TOOL     |
//        WANTS_CONFIG              |
        INSTALLS_TOOLBOX_PAGE     |
        INSTALLS_CONTEXTMENU_ITEMS  |
//        WANTS_NMEA_EVENTS         |
//        WANTS_NMEA_SENTENCES        |
        //    USES_AUI_MANAGER            |
//        WANTS_PREFERENCES         |
        //    WANTS_ONPAINT_VIEWPORT      |
        WANTS_PLUGIN_MESSAGING    |
        WANTS_MOUSE_EVENTS        |
        WANTS_KEYBOARD_EVENTS
    );
}

bool testplugin_pi::DeInit(void)
{
    if(m_tpControlDialogImpl)
      {
          m_tpControlDialogImpl->Close();
//          m_ptestplugin_window->Destroy(); //Gives a Segmentation fault
      }
      return true;
}

int testplugin_pi::GetAPIVersionMajor()
{
      return API_VERSION_MAJOR;
}

int testplugin_pi::GetAPIVersionMinor()
{
      return API_VERSION_MINOR;
}

int testplugin_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int testplugin_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxString testplugin_pi::GetCommonName()
{
      return _("testplugin");
}

wxString testplugin_pi::GetShortDescription()
{
      return _("testplugin PlugIn for OpenCPN");
}

wxString testplugin_pi::GetLongDescription()
{
      return _("testplugin PlugIn for OpenCPN\n\
demonstrates PlugIn processing of NMEA messages.");

}

int testplugin_pi::GetToolbarToolCount(void)
{
      return 1;
}

void testplugin_pi::OnToolbarToolCallback(int id)
{
    m_iCallerId = id;
    ToggleToolbarIcon();
}

void testplugin_pi::OnToolbarToolDownCallback(int id)
{
    return;
}

void testplugin_pi::OnToolbarToolUpCallback(int id)
{
    m_ptpicons->SetScaleFactor();
    return;
}

void testplugin_pi::ShowPreferencesDialog( wxWindow* parent )
{
    
}

void testplugin_pi::SetPluginMessage(wxString &message_id, wxString &message_body)
{
    g_ptpJSON->ProcessMessage(message_id, message_body);
    return;
}

bool testplugin_pi::KeyboardEventHook( wxKeyEvent &event )
{
    bool bret = FALSE;
    
    if( event.GetKeyCode() < 128 )            //ascii
    {
        int key_char = event.GetKeyCode();
        
        if ( event.ControlDown() )
            key_char -= 64;
        
        switch( key_char ) {
            case WXK_CONTROL_W:                      // Ctrl W
                if ( event.ShiftDown() ) { // Shift-Ctrl-W
                    if(event.GetEventType() == wxEVT_KEY_DOWN) {
                        OnToolbarToolDownCallback( m_testplugin_button_id);
                    }
                    bret = TRUE;
                } else bret = FALSE;
                break;
        }
    }
    if(bret) RequestRefresh(m_parent_window);
    return bret;
}

bool testplugin_pi::MouseEventHook( wxMouseEvent &event )
{
    bool bret = FALSE;
    
    if(m_tpControlDialogImpl->IsVisible()) {
        DEBUGSL("ControlDIalogImpl");
        if(event.LeftDown()) {
            DEBUGSL("LeftDown");
            m_click_lat = m_cursor_lat;
            m_click_lon = m_cursor_lon;
            m_tpControlDialogImpl->SetLatLon( m_cursor_lat, m_cursor_lon );
            bret = TRUE;
        }
        
        if(event.LeftUp()) {
            bret = TRUE;
        }
    }
    
    return bret;
}                        

void testplugin_pi::SetCursorLatLon(double lat, double lon)
{
    if(m_tpControlDialogImpl->IsShown()) {
        m_cursor_lat = lat;
        m_cursor_lon = lon;
        DEBUGST("SetCursorLatLon, Lat: ");
        DEBUGCONT(lat);
        DEBUGCONT(", Lon: ");
        DEBUGEND(lon);
    }
}

wxBitmap *testplugin_pi::GetPlugInBitmap()
{
    return &m_ptpicons->m_bm_testplugin_pi;
}

void testplugin_pi::appendOSDirSlash(wxString* pString)
{
    wxChar sep = wxFileName::GetPathSeparator();
    
    if (pString->Last() != sep)
        pString->Append(sep);
}

void testplugin_pi::ToggleToolbarIcon( void )
{
    if(m_btpDialog) {
        m_btpDialog = false;
        SetToolbarItemState( m_testplugin_button_id, false );
        m_tpControlDialogImpl->Hide();
    } else {
        m_btpDialog = true;
        SetToolbarItemState( m_testplugin_button_id, true  );
        m_tpControlDialogImpl->Show();
    }
}

void testplugin_pi::GetODAPI()
{
    wxJSONValue jMsg;
    wxJSONWriter writer;
    wxString    MsgString;
    jMsg[wxT("Source")] = wxT("TESTPLUGIN_PI");
    jMsg[wxT("Type")] = wxT("Request");
    jMsg[wxT("Msg")] = wxS("GetAPIAddresses");
    jMsg[wxT("MsgId")] = wxS("GetAPIAddresses");
    writer.Write( jMsg, MsgString );
    SendPluginMessage( wxS("OCPN_DRAW_PI"), MsgString );
    if(g_ReceivedODAPIMessage != wxEmptyString &&  g_ReceivedODAPIJSONMsg[wxT("MsgId")].AsString() == wxS("GetAPIAddresses")) {
        wxString sptr = g_ReceivedODAPIJSONMsg[_T("OD_FindPointInAnyBoundary")].AsString();
        if(sptr != _T("null")) {
            sscanf(sptr.To8BitData().data(), "%p", &m_pOD_FindPointInAnyBoundary);
        }
        sptr = g_ReceivedODAPIJSONMsg[_T("OD_FindClosestBoundaryLineCrossing")].AsString();
        if(sptr != _T("null")) {
            sscanf(sptr.To8BitData().data(), "%p", &m_pODFindClosestBoundaryLineCrossing);
        }
        sptr = g_ReceivedODAPIJSONMsg[_T("OD_FindFirstBoundaryLineCrossing")].AsString();
        if(sptr != _T("null")) {
            sscanf(sptr.To8BitData().data(), "%p", &m_pODFindFirstBoundaryLineCrossing);
        }
        sptr = g_ReceivedODAPIJSONMsg[_T("OD_CreateBoundary")].AsString();
        if(sptr != _T("null")) {
            sscanf(sptr.To8BitData().data(), "%p", &m_pODCreateBoundary);
        }
        sptr = g_ReceivedODAPIJSONMsg[_T("OD_CreateBoundaryPoint")].AsString();
        if(sptr != _T("null")) {
            sscanf(sptr.To8BitData().data(), "%p", &m_pODCreateBoundaryPoint);
        }
        sptr = g_ReceivedODAPIJSONMsg[_T("OD_CreateTextPoint")].AsString();
        if(sptr != _T("null")) {
            sscanf(sptr.To8BitData().data(), "%p", &m_pODCreateTextPoint);
        }
    }
}

void testplugin_pi::FindClosestBoundaryLineCrossing(FindClosestBoundaryLineCrossing_t *pFCPBLC)
{
    if((*m_pODFindClosestBoundaryLineCrossing)(pFCPBLC)) {
        delete pFCPBLC;
    }
    delete pFCPBLC;
}

bool testplugin_pi::CreateBoundaryPoint(CreateBoundaryPoint_t* pCBP)
{
    return (*m_pODCreateBoundaryPoint)(pCBP);
}

bool testplugin_pi::CreateBoundary(CreateBoundary_t* pCB)
{
    return false;
}

bool testplugin_pi::CreateTextPoint(CreateTextPoint_t* pCTP)
{
    return (*m_pODCreateTextPoint)(pCTP);
}
