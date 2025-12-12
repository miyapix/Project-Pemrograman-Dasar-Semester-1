#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <vector>
#include <string>

// Forward declarations — cukup agar compiler tahu ada kelas ini
class Feedback;
class Rating;

struct ReportItem {
    std::string username;
    std::string description;
};

class Report {
private:
    std::vector<ReportItem> reports;

    // deklarasi member yang dipakai di Report.cpp
    Feedback* feedback = nullptr;
    Rating* rating = nullptr;

public:
    void addReport(const std::string& username, const std::string& description);
    void showReports();
    void generateReport();
    void setFeedback(Feedback* fb) { feedback = fb; }
    void setRating(Rating* rt)   { rating = rt; }
};

#endif

