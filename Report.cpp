#include "Report.h"

void Report::generateReport() {
    std::cout << "=== Laporan Konsultasi ===\n\n";
    if (feedback) feedback->showFeedbacks();
    if (rating) rating->showRatings();
}
