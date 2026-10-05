void showDayOverview() {
    printf("Day Overview:\n");
    for (int i = 0; taskCount > i; ++i) {
        printf("Task: %s, Priority: %d, Category: %s, Time Slot: %s\n",
               tasks[i].name, tasks[i].priority, tasks[i].category, tasks[i].timeSlot);
    }
}