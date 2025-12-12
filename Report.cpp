#include "Report.h"
#include "Feedback.h"
#include "Rating.h"


void Report::generateReport() {
    std::cout << "=== Laporan Konsultasi ===\n\n";
    if (feedback) feedback->showFeedbacks();
    if (rating) rating->showRatings();
}
