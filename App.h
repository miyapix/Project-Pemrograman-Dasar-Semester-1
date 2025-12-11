#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include "User.h"

struct ChatItem {
    std::string mahasiswaUsername;
    std::string message;
    std::string reply;
};

struct RatingItem {
    std::string username;
    int score;
};

struct FeedbackItem {
    std::string username;
    std::string feedback;
};

struct ReportItem {
    std::string username;
    std::string report;
};

class App {
private:
    User users;
    std::vector<ChatItem> chats;
    std::vector<RatingItem> ratings;
    std::vector<FeedbackItem> feedbacks;
    std::vector<ReportItem> reports;

public:
    void run();
    void showMainMenu();
    void registerMenu();
    void loginMenu();
    void mahasiswaMenu();
    void konselorMenu();
    void chatMenu();
    void riwayatChatMahasiswa();
    void feedbackMenu();
    void ratingMenu();
    void reportMenu();
    void balasChatMenu();
};

#endif
