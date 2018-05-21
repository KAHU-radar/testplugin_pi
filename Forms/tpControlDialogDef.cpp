///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tpControlDialogDef.h"

///////////////////////////////////////////////////////////////////////////

tpControlDialogDef::tpControlDialogDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_SizerControl = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 0, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableRow( 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_notebookControl = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelGeneral = new wxPanel( m_notebookControl, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebookControl->AddPage( m_panelGeneral, _("General"), false );
	m_panelJSON = new wxPanel( m_notebookControl, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_fgSizerJSON = new wxFlexGridSizer( 0, 0, 0, 0 );
	m_fgSizerJSON->SetFlexibleDirection( wxBOTH );
	m_fgSizerJSON->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextJSONFile = new wxStaticText( m_panelJSON, wxID_ANY, _("Select JSON file"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextJSONFile->Wrap( -1 );
	m_fgSizerJSON->Add( m_staticTextJSONFile, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_filePickerJSON = new wxFilePickerCtrl( m_panelJSON, wxID_ANY, wxEmptyString, _("Select a JSON file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	m_fgSizerJSON->Add( m_filePickerJSON, 0, wxALL, 5 );
	
	m_buttonProcessJSON = new wxButton( m_panelJSON, wxID_ANY, _("Process JSON"), wxDefaultPosition, wxDefaultSize, 0 );
	m_fgSizerJSON->Add( m_buttonProcessJSON, 0, wxALL, 5 );
	
	
	m_fgSizerJSON->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	m_panelJSON->SetSizer( m_fgSizerJSON );
	m_panelJSON->Layout();
	m_fgSizerJSON->Fit( m_panelJSON );
	m_notebookControl->AddPage( m_panelJSON, _("JSON"), false );
	m_panelODAPI = new wxPanel( m_notebookControl, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_fgSizerODAPI = new wxFlexGridSizer( 0, 0, 0, 0 );
	m_fgSizerODAPI->AddGrowableCol( 0 );
	m_fgSizerODAPI->AddGrowableRow( 0 );
	m_fgSizerODAPI->SetFlexibleDirection( wxBOTH );
	m_fgSizerODAPI->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_notebookODAPI = new wxNotebook( m_panelODAPI, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelODAPICreateBoundary = new wxPanel( m_notebookODAPI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticBoundaryName = new wxStaticText( m_panelODAPICreateBoundary, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticBoundaryName->Wrap( -1 );
	fgSizer5->Add( m_staticBoundaryName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlName = new wxTextCtrl( m_panelODAPICreateBoundary, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_textCtrlName, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticTextType = new wxStaticText( m_panelODAPICreateBoundary, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextType->Wrap( -1 );
	fgSizer5->Add( m_staticTextType, 0, wxALL, 5 );
	
	wxString m_choiceTypeChoices[] = { _("Exclusion"), _("Inclusion"), _("Neither") };
	int m_choiceTypeNChoices = sizeof( m_choiceTypeChoices ) / sizeof( wxString );
	m_choiceType = new wxChoice( m_panelODAPICreateBoundary, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTypeNChoices, m_choiceTypeChoices, 0 );
	m_choiceType->SetSelection( 0 );
	fgSizer5->Add( m_choiceType, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	m_checkBoxBoundaryActive = new wxCheckBox( m_panelODAPICreateBoundary, wxID_ANY, _("Active"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_checkBoxBoundaryActive->SetValue(true); 
	fgSizer5->Add( m_checkBoxBoundaryActive, 0, wxALL, 5 );
	
	m_checkBoxBoundaryVisible = new wxCheckBox( m_panelODAPICreateBoundary, wxID_ANY, _("Visible"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxBoundaryVisible->SetValue(true); 
	fgSizer5->Add( m_checkBoxBoundaryVisible, 1, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextLineColour = new wxStaticText( m_panelODAPICreateBoundary, wxID_ANY, _("Line Colour"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLineColour->Wrap( -1 );
	fgSizer6->Add( m_staticTextLineColour, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourPickerLineColour = new wxColourPickerCtrl( m_panelODAPICreateBoundary, wxID_ANY, wxColour( 255, 0, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer6->Add( m_colourPickerLineColour, 0, wxALL, 5 );
	
	
	fgSizer5->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextFillColour = new wxStaticText( m_panelODAPICreateBoundary, wxID_ANY, _("Fill Colour"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFillColour->Wrap( -1 );
	fgSizer7->Add( m_staticTextFillColour, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourPickerFillColour = new wxColourPickerCtrl( m_panelODAPICreateBoundary, wxID_ANY, wxColour( 255, 0, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( m_colourPickerFillColour, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	
	fgSizer5->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	m_staticTextBoundaryPointsList = new wxStaticText( m_panelODAPICreateBoundary, wxID_ANY, _("Boundary Points"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBoundaryPointsList->Wrap( -1 );
	fgSizer5->Add( m_staticTextBoundaryPointsList, 0, wxALL, 5 );
	
	wxArrayString m_checkListBoundaryPointListChoices;
	m_checkListBoundaryPointList = new wxCheckListBox( m_panelODAPICreateBoundary, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_checkListBoundaryPointListChoices, 0 );
	fgSizer5->Add( m_checkListBoundaryPointList, 1, wxALL, 5 );
	
	m_buttonCreateBoundary = new wxButton( m_panelODAPICreateBoundary, wxID_ANY, _("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_buttonCreateBoundary, 0, wxALL, 5 );
	
	
	m_panelODAPICreateBoundary->SetSizer( fgSizer5 );
	m_panelODAPICreateBoundary->Layout();
	fgSizer5->Fit( m_panelODAPICreateBoundary );
	m_notebookODAPI->AddPage( m_panelODAPICreateBoundary, _("Create Boundary"), false );
	m_panelODAPICreateBoundaryPoint = new wxPanel( m_notebookODAPI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer8->AddGrowableCol( 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer10->AddGrowableCol( 0 );
	fgSizer10->AddGrowableCol( 1 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextBPName = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBPName->Wrap( -1 );
	fgSizer10->Add( m_staticTextBPName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlBoundaryPointName = new wxTextCtrl( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer10->Add( m_textCtrlBoundaryPointName, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	wxFlexGridSizer* fgSizer16;
	fgSizer16 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer16->SetFlexibleDirection( wxBOTH );
	fgSizer16->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextBoundaryPointType = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBoundaryPointType->Wrap( -1 );
	fgSizer16->Add( m_staticTextBoundaryPointType, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choiceBoundaryPointTypeChoices[] = { _("Exclusion"), _("Inclusion"), _("Neither") };
	int m_choiceBoundaryPointTypeNChoices = sizeof( m_choiceBoundaryPointTypeChoices ) / sizeof( wxString );
	m_choiceBoundaryPointType = new wxChoice( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBoundaryPointTypeNChoices, m_choiceBoundaryPointTypeChoices, 0 );
	m_choiceBoundaryPointType->SetSelection( 0 );
	fgSizer16->Add( m_choiceBoundaryPointType, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer16, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextIconName = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Icon Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextIconName->Wrap( -1 );
	fgSizer18->Add( m_staticTextIconName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlBoundaryPointIconName = new wxTextCtrl( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer18->Add( m_textCtrlBoundaryPointIconName, 0, wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer18, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer9->AddGrowableCol( 1 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextLat = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Lat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLat->Wrap( -1 );
	fgSizer9->Add( m_staticTextLat, 0, wxALL, 5 );
	
	m_textCtrlLatitude = new wxTextCtrl( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_textCtrlLatitude, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer9, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->AddGrowableCol( 1 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextLon = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Lon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLon->Wrap( -1 );
	fgSizer11->Add( m_staticTextLon, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlLongitude = new wxTextCtrl( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_textCtrlLongitude, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer11, 1, wxEXPAND, 5 );
	
	m_checkBoxBoundaryPointVisible = new wxCheckBox( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Visible"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_checkBoxBoundaryPointVisible->SetValue(true); 
	fgSizer10->Add( m_checkBoxBoundaryPointVisible, 1, wxALL, 5 );
	
	m_checkBoxRingsVisible = new wxCheckBox( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Rings Visible"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_checkBoxRingsVisible->SetValue(true); 
	fgSizer10->Add( m_checkBoxRingsVisible, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText10 = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Number of Rings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer13->Add( m_staticText10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choiceBoundaryPointRingNumberChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9"), _("10") };
	int m_choiceBoundaryPointRingNumberNChoices = sizeof( m_choiceBoundaryPointRingNumberChoices ) / sizeof( wxString );
	m_choiceBoundaryPointRingNumber = new wxChoice( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBoundaryPointRingNumberNChoices, m_choiceBoundaryPointRingNumberChoices, 0 );
	m_choiceBoundaryPointRingNumber->SetSelection( 0 );
	fgSizer13->Add( m_choiceBoundaryPointRingNumber, 0, wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer13, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer131;
	fgSizer131 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer131->SetFlexibleDirection( wxBOTH );
	fgSizer131->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1RingStep = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Rings Step"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1RingStep->Wrap( -1 );
	fgSizer131->Add( m_staticText1RingStep, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlBoundaryPointRingStep = new wxTextCtrl( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("0.5"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	#ifdef __WXGTK__
	if ( !m_textCtrlBoundaryPointRingStep->HasFlag( wxTE_MULTILINE ) )
	{
	m_textCtrlBoundaryPointRingStep->SetMaxLength( 4 );
	}
	#else
	m_textCtrlBoundaryPointRingStep->SetMaxLength( 4 );
	#endif
	fgSizer131->Add( m_textCtrlBoundaryPointRingStep, 0, wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer131, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer14;
	fgSizer14 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer14->SetFlexibleDirection( wxBOTH );
	fgSizer14->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextRinUnits = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Step Units"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRinUnits->Wrap( -1 );
	fgSizer14->Add( m_staticTextRinUnits, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choiceBoundaryPointRingUnitsChoices[] = { _("Nautical Miles"), _("Kilometers") };
	int m_choiceBoundaryPointRingUnitsNChoices = sizeof( m_choiceBoundaryPointRingUnitsChoices ) / sizeof( wxString );
	m_choiceBoundaryPointRingUnits = new wxChoice( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBoundaryPointRingUnitsNChoices, m_choiceBoundaryPointRingUnitsChoices, 0 );
	m_choiceBoundaryPointRingUnits->SetSelection( 0 );
	fgSizer14->Add( m_choiceBoundaryPointRingUnits, 0, wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer14, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer15;
	fgSizer15 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer15->SetFlexibleDirection( wxBOTH );
	fgSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextRingColour = new wxStaticText( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Ring Colour"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRingColour->Wrap( -1 );
	fgSizer15->Add( m_staticTextRingColour, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourPickerBoundaryPointRingColour = new wxColourPickerCtrl( m_panelODAPICreateBoundaryPoint, wxID_ANY, wxColour( 255, 0, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer15->Add( m_colourPickerBoundaryPointRingColour, 0, wxALL, 5 );
	
	
	fgSizer10->Add( fgSizer15, 1, wxEXPAND, 5 );
	
	
	fgSizer10->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_buttonCreateBoundaryPoint = new wxButton( m_panelODAPICreateBoundaryPoint, wxID_ANY, _("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer10->Add( m_buttonCreateBoundaryPoint, 0, wxALL, 5 );
	
	
	fgSizer8->Add( fgSizer10, 1, wxEXPAND, 5 );
	
	
	m_panelODAPICreateBoundaryPoint->SetSizer( fgSizer8 );
	m_panelODAPICreateBoundaryPoint->Layout();
	fgSizer8->Fit( m_panelODAPICreateBoundaryPoint );
	m_notebookODAPI->AddPage( m_panelODAPICreateBoundaryPoint, _("Create Boundary Point"), true );
	m_panelODAPICreateTextPoint = new wxPanel( m_notebookODAPI, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_fgSizerTextPoint = new wxFlexGridSizer( 0, 1, 0, 0 );
	m_fgSizerTextPoint->AddGrowableCol( 0 );
	m_fgSizerTextPoint->AddGrowableRow( 0 );
	m_fgSizerTextPoint->SetFlexibleDirection( wxBOTH );
	m_fgSizerTextPoint->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer19->AddGrowableCol( 0 );
	fgSizer19->AddGrowableCol( 1 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextTextPointName = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointName->Wrap( -1 );
	fgSizer19->Add( m_staticTextTextPointName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlTextPointName = new wxTextCtrl( m_panelODAPICreateTextPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textCtrlTextPointName, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticTextTextPointIconName = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Icon Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointIconName->Wrap( -1 );
	fgSizer19->Add( m_staticTextTextPointIconName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlTextPointIconName = new wxTextCtrl( m_panelODAPICreateTextPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_textCtrlTextPointIconName, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	wxFlexGridSizer* fgSizer20;
	fgSizer20 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer20->AddGrowableCol( 1 );
	fgSizer20->SetFlexibleDirection( wxBOTH );
	fgSizer20->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextTextPointLat = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Lat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointLat->Wrap( -1 );
	fgSizer20->Add( m_staticTextTextPointLat, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlTextPointLatitude = new wxTextCtrl( m_panelODAPICreateTextPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer20->Add( m_textCtrlTextPointLatitude, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	fgSizer19->Add( fgSizer20, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer21->AddGrowableCol( 1 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextTextPointLon = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Lon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointLon->Wrap( -1 );
	fgSizer21->Add( m_staticTextTextPointLon, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrlTextPointLongitude = new wxTextCtrl( m_panelODAPICreateTextPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer21->Add( m_textCtrlTextPointLongitude, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	fgSizer19->Add( fgSizer21, 1, wxEXPAND, 5 );
	
	m_checkBoxTextPointVisible = new wxCheckBox( m_panelODAPICreateTextPoint, wxID_ANY, _("Visible"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_checkBoxTextPointVisible->SetValue(true); 
	fgSizer19->Add( m_checkBoxTextPointVisible, 0, wxALL, 5 );
	
	
	m_fgSizerTextPoint->Add( fgSizer19, 1, wxEXPAND, 5 );
	
	m_staticTextTextPointText = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Text to Display with Point"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointText->Wrap( -1 );
	m_fgSizerTextPoint->Add( m_staticTextTextPointText, 0, wxALL, 5 );
	
	m_textCtrlTextPointTextToDisplay = new wxTextCtrl( m_panelODAPICreateTextPoint, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	m_fgSizerTextPoint->Add( m_textCtrlTextPointTextToDisplay, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer22->AddGrowableCol( 1 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextTextPointTextPosition = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Text position relative to point"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointTextPosition->Wrap( -1 );
	fgSizer22->Add( m_staticTextTextPointTextPosition, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choiceTextPointTextPositionChoices[] = { _("Top"), _("Top Centre"), _("Bottom"), _("Bottom Centre"), _("Centre"), _("Right"), _("Left") };
	int m_choiceTextPointTextPositionNChoices = sizeof( m_choiceTextPointTextPositionChoices ) / sizeof( wxString );
	m_choiceTextPointTextPosition = new wxChoice( m_panelODAPICreateTextPoint, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceTextPointTextPositionNChoices, m_choiceTextPointTextPositionChoices, 0 );
	m_choiceTextPointTextPosition->SetSelection( 0 );
	fgSizer22->Add( m_choiceTextPointTextPosition, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticTextTextPointTextColour = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Text Colour"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointTextColour->Wrap( -1 );
	fgSizer22->Add( m_staticTextTextPointTextColour, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourPickerTextPointTextColour = new wxColourPickerCtrl( m_panelODAPICreateTextPoint, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer22->Add( m_colourPickerTextPointTextColour, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticTextTextPointBackgroundColour = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Background Colour"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointBackgroundColour->Wrap( -1 );
	fgSizer22->Add( m_staticTextTextPointBackgroundColour, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_colourPickerTextPointTextBackgroundColour = new wxColourPickerCtrl( m_panelODAPICreateTextPoint, wxID_ANY, wxColour( 255, 255, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer22->Add( m_colourPickerTextPointTextBackgroundColour, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticTextTextPointBackgroundTransparancy = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Background Transparancy"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointBackgroundTransparancy->Wrap( -1 );
	fgSizer22->Add( m_staticTextTextPointBackgroundTransparancy, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_sliderTextPointBackgroundTransparency = new wxSlider( m_panelODAPICreateTextPoint, wxID_ANY, 100, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	fgSizer22->Add( m_sliderTextPointBackgroundTransparency, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	m_fgSizerDisplayText = new wxFlexGridSizer( 0, 2, 0, 0 );
	m_fgSizerDisplayText->AddGrowableCol( 1 );
	m_fgSizerDisplayText->AddGrowableRow( 0 );
	m_fgSizerDisplayText->SetFlexibleDirection( wxBOTH );
	m_fgSizerDisplayText->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextTextPointFont = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Text Font"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointFont->Wrap( -1 );
	m_fgSizerDisplayText->Add( m_staticTextTextPointFont, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticTextTextPointTextFontExample = new wxStaticText( m_panelODAPICreateTextPoint, wxID_ANY, _("Example"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTextPointTextFontExample->Wrap( -1 );
	m_fgSizerDisplayText->Add( m_staticTextTextPointTextFontExample, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer22->Add( m_fgSizerDisplayText, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_buttonTextPointFonts = new wxButton( m_panelODAPICreateTextPoint, wxID_ANY, _("Fonts"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer22->Add( m_buttonTextPointFonts, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	wxString m_radioBoxTextPointTextDisplayChoices[] = { _("Always"), _("On Rollover Only"), _("Never") };
	int m_radioBoxTextPointTextDisplayNChoices = sizeof( m_radioBoxTextPointTextDisplayChoices ) / sizeof( wxString );
	m_radioBoxTextPointTextDisplay = new wxRadioBox( m_panelODAPICreateTextPoint, wxID_ANY, _("Show Display Text"), wxDefaultPosition, wxDefaultSize, m_radioBoxTextPointTextDisplayNChoices, m_radioBoxTextPointTextDisplayChoices, 1, wxRA_SPECIFY_ROWS );
	m_radioBoxTextPointTextDisplay->SetSelection( 0 );
	fgSizer22->Add( m_radioBoxTextPointTextDisplay, 0, wxALL, 5 );
	
	
	m_fgSizerTextPoint->Add( fgSizer22, 1, wxEXPAND, 5 );
	
	m_buttonCreateTextPoint = new wxButton( m_panelODAPICreateTextPoint, wxID_ANY, _("Create"), wxDefaultPosition, wxDefaultSize, 0 );
	m_fgSizerTextPoint->Add( m_buttonCreateTextPoint, 0, wxALL, 5 );
	
	
	m_panelODAPICreateTextPoint->SetSizer( m_fgSizerTextPoint );
	m_panelODAPICreateTextPoint->Layout();
	m_fgSizerTextPoint->Fit( m_panelODAPICreateTextPoint );
	m_notebookODAPI->AddPage( m_panelODAPICreateTextPoint, _("Create Text Point"), false );
	
	m_fgSizerODAPI->Add( m_notebookODAPI, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panelODAPI->SetSizer( m_fgSizerODAPI );
	m_panelODAPI->Layout();
	m_fgSizerODAPI->Fit( m_panelODAPI );
	m_notebookControl->AddPage( m_panelODAPI, _("ODAPI"), true );
	
	fgSizer3->Add( m_notebookControl, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 0, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizerOKCancel;
	bSizerOKCancel = new wxBoxSizer( wxHORIZONTAL );
	
	Cancel = new wxButton( this, wxID_ANY, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerOKCancel->Add( Cancel, 0, wxALL, 5 );
	
	
	fgSizer4->Add( bSizerOKCancel, 1, wxEXPAND, 5 );
	
	
	fgSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	
	m_SizerControl->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( m_SizerControl );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonProcessJSON->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::tpControlOnClickProcessJSON ), NULL, this );
	m_buttonCreateBoundary->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickCreateBoundary ), NULL, this );
	m_buttonCreateBoundaryPoint->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickCreateBoundaryPoint ), NULL, this );
	m_buttonTextPointFonts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickFonts ), NULL, this );
	m_buttonCreateTextPoint->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickCreateTextPoint ), NULL, this );
	Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::tpControlCancelClick ), NULL, this );
}

tpControlDialogDef::~tpControlDialogDef()
{
	// Disconnect Events
	m_buttonProcessJSON->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::tpControlOnClickProcessJSON ), NULL, this );
	m_buttonCreateBoundary->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickCreateBoundary ), NULL, this );
	m_buttonCreateBoundaryPoint->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickCreateBoundaryPoint ), NULL, this );
	m_buttonTextPointFonts->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickFonts ), NULL, this );
	m_buttonCreateTextPoint->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::OnButtonClickCreateTextPoint ), NULL, this );
	Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( tpControlDialogDef::tpControlCancelClick ), NULL, this );
	
}