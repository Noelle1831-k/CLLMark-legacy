void displayTask(const Task *task) {
    printf("Title: %s\n", task->title);
    printf("Description: %s\n", task->description);
    printf("Deadline: %s\n", task->deadline);
    printf("Priority: %d\n", task->priority);
    printf("Category: %s\n", task->category);
    printf("Status: %s\n", task->isComplete ? "Complete" : "Incomplete");
}