void WaterHistory::logIntake(const char* date, int intake) {
    std::map<std::string, int>::iterator it = history.find(date);
    if (it != history.end()) {
        it->second += intake;
    } else {
        history[date] = intake;
    }
}