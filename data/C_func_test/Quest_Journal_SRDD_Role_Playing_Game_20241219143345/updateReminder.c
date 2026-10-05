void updateReminder() {
    int index;
    printf("Enter reminder index to update: ");
    scanf("%d", &index);
    if (index >= 0 && index < reminderCount) {
        printf("Enter new reminder message: ");
        scanf("%s", reminders[index].message);
        printf("Enter new day: ");
        scanf("%d", &reminders[index].day);
        printf("Enter new month: ");
        scanf("%d", &reminders[index].month);
        printf("Enter new year: ");
        scanf("%d", &reminders[index].year);
    } else {
        printf("Invalid reminder index.\n");
    }
}