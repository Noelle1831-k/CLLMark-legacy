void displayTask(const Task *task) {
    printf("Task: %s\n", task->title);
    printf("Deadline: %s\n", task->deadline);
    printf("Time Slot: %d\n", task->timeSlot);
    printf("Progress: %d%%\n", task->progress);
}