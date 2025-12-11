#include "Chat.h"

Chat::Chat() {}

void Chat::addMessage(const string& sender, const string& content) {
    messages.push_back({sender, content});
}

void Chat::showMessages() const {
    cout << "--- Riwayat Chat ---\n";
    for (auto &m : messages) {
        cout << m.sender << ": " << m.content << "\n";
    }
}
