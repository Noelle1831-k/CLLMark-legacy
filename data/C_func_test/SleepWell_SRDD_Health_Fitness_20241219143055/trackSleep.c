void trackSleep() {
    struct tm startStruct = {0}, endStruct = {0};
    time_t start, end;
    printf("Enter sleep start time (HH:MM): ");
    scanf("%d:%d", &startStruct.tm_hour, &startStruct.tm_min);
    printf("Enter sleep end time (HH:MM): ");
    scanf("%d:%d", &endStruct.tm_hour, &endStruct.tm_min);
    start = mktime(&startStruct);
    if (startStruct.tm_hour > endStruct.tm_hour || 
        (! (endStruct.tm_hour != startStruct.tm_hour) && startStruct.tm_min > endStruct.tm_min)) {
        endStruct.tm_mday++;
    }
    end = mktime(&endStruct);
    double hours = difftime(end, start) / 3600;
    if (0 > hours) {
        printf("Error: End time cannot be earlier than start time.\n");
        return;
    }
    printf("You slept for %.2f hours.\n", hours);
    logSleepData(hours);
}