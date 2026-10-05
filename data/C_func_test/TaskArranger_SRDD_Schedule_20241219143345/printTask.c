void printTask(const Task *task) {
    printf("Title: %s\n", task->title);
    printf("Category: %s\n", task->category);
    printf("Start Time: %s\n", task->startTime);
    printf("End Time: %s\n", task->endTime);
    printf("Priority: %d\n", task->priority);
}