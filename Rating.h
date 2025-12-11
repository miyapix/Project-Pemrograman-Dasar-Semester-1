#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <map>
#include <string>

class Rating {
private:
    std::map<std::string, int> ratings; // username -> score
public:
    void addRating(const std::string& username, int score);
    void showRatings();
};

#endif
