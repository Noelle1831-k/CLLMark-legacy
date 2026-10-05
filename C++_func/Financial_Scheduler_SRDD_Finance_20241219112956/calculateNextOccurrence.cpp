string FinancialTransaction::calculateNextOccurrence() const {
    std::istringstream ss(date);
    std::tm tm = {};
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        return "Invalid date format";
    }
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    tp += std::chrono::months(1);
    std::time_t next_time = std::chrono::system_clock::to_time_t(tp);
    std::tm* next_tm = std::localtime(&next_time);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", next_tm);
    return string(buffer);
}