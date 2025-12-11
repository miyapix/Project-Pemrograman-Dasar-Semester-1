#include "Feedback.h"

void Feedback::addFeedback(const std::string& username, const std::string& message) {
    feedbacks.push_back({username, message});
    std::cout << "Feedback berhasil ditambahkan.\n";
}

void Feedback::showFeedbacks() {
    std::cout << "=== Daftar Feedback / Penilaian ===\n";
    for (auto &f : feedbacks) {
        std::cout << "User: " << f.username << " | Feedback: " << f.message << "\n";
    }
}
