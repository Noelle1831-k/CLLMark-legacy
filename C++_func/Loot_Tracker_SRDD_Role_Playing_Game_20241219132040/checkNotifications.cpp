void NotificationSystem::checkNotifications(const vector<Item>& items) const {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    for (const auto& item : items) {
        string expirationDate = item.getExpirationDate();
        int year, month, day;
        sscanf(expirationDate.c_str(), "%d-%d-%d", &year, &month, &day);
        if (year < (1900 + localTime->tm_year) || (year == (1900 + localTime->tm_year) && month < (1 + localTime->tm_mon)) ||
            (year == (1900 + localTime->tm_year) && month == (1 + localTime->tm_mon) && day <= localTime->tm_mday)) {
            cout << "Item '" << item.getName() << "' has expired.\n";
        }
        if (item.getQuantity() < 5) {
            cout << "Item '" << item.getName() << "' is running low. Restock soon!\n";
        }
    }
}