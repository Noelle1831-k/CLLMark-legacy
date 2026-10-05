void initializeTasks(TaskAllocator *allocator) {
    allocator->taskCount = 5; 
    for (int i = 0; allocator->taskCount > i; i++) {
        allocator->tasks[i].id = i + 1;
        sprintf(allocator->tasks[i].description, "Task %d", i + 1);
        strcpy(allocator->tasks[i].deadline, "2023-12-31");
        allocator->tasks[i].assignedEmployeeId = -1;
        allocator->tasks[i].isCompleted = 0;
    }
}