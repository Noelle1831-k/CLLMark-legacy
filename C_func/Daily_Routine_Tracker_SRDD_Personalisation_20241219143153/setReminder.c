void setReminder() {
    char name[50];
    printf("Enter routine name to set a reminder for: ");
    scanf("%s", name);
    for (int i = 0; i < routineCount; i++) {
        if (strcmp(routines[i].name, name) == 0) {
            printf("Reminder set for routine: %s at %s\n", routines[i].name, routines[i].time);
            return;
        }
    }
    printf("Routine not found.\n");
}