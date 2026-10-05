tm stringToTime(const string& timeStr) {
    tm timeStruct = {};
    istringstream ss(timeStr);
    ss >> get_time(&timeStruct, "%H:%M");
    return timeStruct;
}