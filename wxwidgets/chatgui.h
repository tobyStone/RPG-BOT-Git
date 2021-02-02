
#ifndef CHATGUI_H
#define CHATGUI_H
#define _CRT_SECURE_NO_WARNINGS


#include <wx/wx.h>
#include <memory>

class ChatLogic;

// middle part of the window containing the chat between user and chatbot
class ChatBotPanelDialog : public wxScrolledWindow

{
private:

	wxBoxSizer *_dialogSizer;
	wxBitmap _image;
	std::unique_ptr<ChatLogic> _chatLogic;

public:

	ChatBotPanelDialog(wxWindow* parent, wxWindowID id);
	~ChatBotPanelDialog();

	//getter
	ChatLogic* GetChatLogicHandle() { return _chatLogic.get(); }

	//events
	void paintEvent(wxPaintEvent& evt);
	void paintNow();
	void render(wxDC& dc);

	void AddDialogItem(wxString text, bool isFromUser = true);
	void PrintChatbotResponse(std::string response);

	DECLARE_EVENT_TABLE();


};

//dialogue that is shown in ChatBotPanelDialog
class ChatBotPanelDialogItem : public wxPanel
{
private: 

	wxStaticBitmap *_chatBotImg;
	wxStaticText* _chatBotTxt;

public:

	//constructor/destructor
	ChatBotPanelDialogItem(wxPanel* parent, wxString text, bool isFromUser);
};

//frame containing all control elements
class ChatBotFrame : public wxFrame
{

private:

	ChatBotPanelDialog* _panelDialog;
	wxTextCtrl* _userTextCtrl;

	//events
	void OnEnter(wxCommandEvent& WXUNUSED(event));


public: 

	//constructor/destructor
	ChatBotFrame(const wxString &title);
};

//control panel for background image dispaly
class ChatBotFrameImagePanel : public wxPanel
{
private:
	//control elements
	wxBitmap _image;

public: 

	//constructor/destructor
	ChatBotFrameImagePanel(wxFrame* parent);

	//events
	void paintEvent(wxPaintEvent& evt);
	void paintNow();
	void render(wxDC& dc);

	DECLARE_EVENT_TABLE();

};

class ChatBotApp : public wxApp
{
public:
	//events
	virtual bool OnInit();
};

#endif /* CHATGUI_H_*/

