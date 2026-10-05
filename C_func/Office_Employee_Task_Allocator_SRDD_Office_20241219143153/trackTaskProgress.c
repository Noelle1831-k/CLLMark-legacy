void trackTaskProgress(TaskAllocator *allocator) {
    printf("Task Progress:\n");
    for (int i = 0; i < allocator->taskCount; i++) {
        printf("Task %d is assigned to Employee %d\n", allocator->tasks[i].id, allocator->tasks[i].assignedEmployeeId);
    }
}