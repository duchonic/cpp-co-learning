#pragma once
#include <wx/timer.h>
#include "PricePublisher.h"
#include "MyFrame_generated.h"
#include "Definitions.h"
#include "XYChart.h"

/**
* This is the class for the principle frame of the application
*/
class MyFrame : public MyFrame_generated {
private:
    PricePublisher pricePublisher;
    DECLARE_EVENT_TABLE()

protected:
    wxTimer m_timer;

public:

    MyFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString)
    : MyFrame_generated(parent, id, title)
    , m_timer(this, TIMER_ID) {
        XYChart *chart = new XYChart();
        m_chartPanel->SetChart(chart->Create());
        pricePublisher.registerPriceObserver(chart);
    }

  
    void OnTimer(wxTimerEvent& event);
    void onStartButtonClicked(wxCommandEvent& event) override;
    void onAddPriceObserverClicked(wxCommandEvent& event) override;
    void onAddHighObserverClicked(wxCommandEvent& event) override;
    void onAddLowObserverClicked(wxCommandEvent& event) override;
    void onAddAverageObserverClicked(wxCommandEvent& event) override;

};
