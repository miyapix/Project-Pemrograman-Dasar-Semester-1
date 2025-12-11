#include "Rating.h"

void Rating::addRating(const std::string& username, int score) {
    ratings[username] = score;
    std::cout << "Rating berhasil ditambahkan.\n";
}

void Rating::showRatings() {
    std::cout << "=== Daftar Rating ===\n";
    for (auto &r : ratings) {
        std::cout << "User: " << r.first << " | Score: " << r.second << "\n";
    }
}
