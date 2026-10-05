void setTaskDeadline(TaskAllocator *allocator) {
    for (int i = 0; i < allocator->taskCount; i++) {
        strcpy(allocator->tasks[i].deadline, "2024-01-31");
    }
}