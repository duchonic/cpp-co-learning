///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul 13 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statusbr.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <iostream>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:

	protected:
		wxButton* m_startButton;
		wxButton* m_button6;
		wxButton* m_button7;
		wxButton* m_button8;
		wxButton* m_button9;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrlPrice;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrlHigh;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrlLow;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textCtrlAverage;
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;

		// Virtual event handlers, overide them in your derived class
		virtual void onStartButtonClicked( wxCommandEvent& event ) { std::cout << "clicked!\n"; event.Skip(); }
		virtual void onAddPriceObserverClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAddHighObserverClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAddLowObserverClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAddAverageObserverClicked( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 725,337 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame();

};

#endif //__NONAME_H__
