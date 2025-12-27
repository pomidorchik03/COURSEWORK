#include <wx/wx.h>


class MyApp : public wxApp
{
public:
    bool OnInit() override;
};


class MyFrame : public wxFrame
{
private:
    wxTextCtrl* textCtrl;

    void OnButtonClick(wxCommandEvent& event);
public:
    MyFrame();
};

wxIMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Enter text",
              wxDefaultPosition, wxSize(400, 200))
{
    wxPanel* panel = new wxPanel(this);

    textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(20, 20), wxSize(340, 30));

    wxButton* button = new wxButton(panel, wxID_ANY, "Show text", wxPoint(20,70), wxSize(150, 30));

    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
}

void MyFrame::OnButtonClick(wxCommandEvent& event)
{
    wxString text = textCtrl->GetValue();

    wxMessageBox(text, "Entered text" , wxOK | wxICON_INFORMATION, this);
}