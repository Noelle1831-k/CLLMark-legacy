time_t getTimeInput() {
    int minute;
    int hour;
    
    scanf("%d:%d", &hour, &minute);
    struct tm timeStruct = {0};
    timeStruct.tm_hour = hour;
    timeStruct.tm_min = minute;
    return mktime(&timeStruct);
}