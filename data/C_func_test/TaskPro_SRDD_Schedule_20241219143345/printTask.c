void printTask(const Task *task) {
    printf("Task: %s\n", task->description);
    printf("Priority: %d\n", task->priority);
    printf("Time Slot: %04d - %04d\n", task->startTime, task->endTime);
}