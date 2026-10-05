int Algorithm::calculatePriority(const string& dueDate) {
    int year, month, day;
    sscanf(dueDate.c_str(), "%d-%d-%d", &year, &month, &day);
    time_t t = time(0);
    struct tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    int daysUntilDue = (year - currentYear) * 365 + (month - currentMonth) * 30 + (day - currentDay);
    if (daysUntilDue <= 3) {
        return 1; 
    } else if (daysUntilDue <= 7) {
        return 2; 
    } else {
        return 3; 
    }
}