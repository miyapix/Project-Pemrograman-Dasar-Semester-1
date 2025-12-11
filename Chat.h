#ifndef CHAT_H
#define CHAT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Message {
    string sender;
    string content;
};

class Chat {
private:
    vector<Message> messages;

public:
    Chat();
    void addMessage(const string& sender, const string& content);
    void showMessages() const;
};

#endif
