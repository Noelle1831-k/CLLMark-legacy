void displayTask(const Task* task) {
    printf("Task ID: %d\n", task->id);
    printf("Name: %s\n", task->name);
    printf("Description: %s\n", task->description);
    printf("Deadline: %s\n", task->deadline);
    printf("Time Slot: %s\n", task->timeSlot);
    printf("Progress: %d%%\n", task->progress);
}