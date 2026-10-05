void addTask(Scheduler *scheduler) {
    if (scheduler->taskCount < MAX_TASKS) {
        char title[MAX_TITLE_LENGTH];
        char deadline[MAX_DATE_LENGTH];
        int timeSlot;
        printf("Enter task title: ");
        getStringInput(title, MAX_TITLE_LENGTH);
        printf("Enter task deadline (YYYY-MM-DD): ");
        getStringInput(deadline, MAX_DATE_LENGTH);
        printf("Enter time slot (in hours): ");
        timeSlot = getIntInput();
        initializeTask(&scheduler->tasks[scheduler->taskCount], title, deadline, timeSlot);
        scheduler->taskCount++;
    } else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }
}