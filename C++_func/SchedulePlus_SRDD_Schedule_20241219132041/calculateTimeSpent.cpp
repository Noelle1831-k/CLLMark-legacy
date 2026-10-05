long TimeTracker::calculateTimeSpent() const {
    return chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
}