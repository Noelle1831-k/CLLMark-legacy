void viewTasks() {
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s, Priority: %d, Category: %s, Time Slot: %s\n", i + 1, tasks[i].name, tasks[i].priority, tasks[i].category, tasks[i].timeSlot);
    }
}