#define _CRT_SECURE_NO_WARNINGS
#ifndef CHATLOGIC_H_
#define CHATLOGIC_H

#include <vector>
#include <string>
#include "chatgui.h"


//forward declarations

class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:

	std::vector<std::unique_ptr<GraphNode>> _nodes;
	GraphNode* _currentNode;
	ChatBot* _chatBot;
	ChatBotPanelDialog* _panelDialog;

	//items for the Levenshtein calculation

	typedef std::vector<std::pair<std::string, std::string>> tokenlist;
	template <typename T>
	void AddAllTokensToElement(std::string tokenID, tokenlist& tokens, T& element);


public:

	//constructor/destructor
	ChatLogic();
	~ChatLogic();

	//getter/setter
	void SetPanelDialogHandle(ChatBotPanelDialog* panelDialog);
	void SetChatbotHandle(ChatBot* chatbot);

	//Levenshtein functions
	void LoadAnswerGraphFromFile(std::string filename);
	void SendMessageToChatbot(std::string message);
	void SendMessageToUser(std::string message);
	wxBitmap* GetImageFromChatbot();
};








#endif // *CHAT_LOGIC_H_*
