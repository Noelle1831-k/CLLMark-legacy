bool isValidTimeFormat(const string& timeStr) {
    if (timeStr.length() != 5 || timeStr[2] != ':') return false;
    int hour = stoi(timeStr.substr(0, 2));
    int minute = stoi(timeStr.substr(3, 2));
    return (hour >= 0 && hour < 24) && (minute >= 0 && minute < 60);
}