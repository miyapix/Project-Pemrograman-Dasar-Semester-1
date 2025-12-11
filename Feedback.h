#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <vector>
#include <string>

struct FeedbackItem {
    std::string username;
    std::string message;
};

class Feedback {
private:
    std::vector<FeedbackItem> feedbacks;
public:
    void addFeedback(const std::string& username, const std::string& message);
    void showFeedbacks();
};

#endif
