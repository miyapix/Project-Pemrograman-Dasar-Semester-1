#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <vector>
#include <string>

struct ReportItem {
    std::string username;   // siapa yang melapor
    std::string description; // isi laporan
};

class Report {
private:
    std::vector<ReportItem> reports;
public:
    void addReport(const std::string& username, const std::string& description);
    void showReports(); // bisa diakses konselor/admin
};

#endif
