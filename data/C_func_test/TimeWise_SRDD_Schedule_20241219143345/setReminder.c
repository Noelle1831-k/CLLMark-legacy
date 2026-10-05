void setReminder() {
    struct tm reminderTime = {0};
    time_t now;
    time(&now);
    struct tm *currentTime = localtime(&now);
    printf("Enter reminder time (hour minute): ");
    scanf("%d %d", &reminderTime.tm_hour, &reminderTime.tm_min);
    reminderTime.tm_sec = 0;
    reminderTime.tm_year = currentTime->tm_year;
    reminderTime.tm_mon = currentTime->tm_mon;
    reminderTime.tm_mday = currentTime->tm_mday;
    if (difftime(mktime(&reminderTime), now) > 0) {
        printf("Reminder set for %02d:%02d.\n", reminderTime.tm_hour, reminderTime.tm_min);
    } else {
        printf("The time you entered is in the past. Please try again.\n");
    }
}