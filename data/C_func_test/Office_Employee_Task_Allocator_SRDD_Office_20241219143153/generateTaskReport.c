void generateTaskReport(TaskAllocator *allocator) {
    printf("Task Report:\n");
    for (int i = 0; i < allocator->taskCount; i++) {
        printf("Task ID: %d, Description: %s, Deadline: %s, Assigned Employee ID: %d, Status: %s\n",
               allocator->tasks[i].id, allocator->tasks[i].description, allocator->tasks[i].deadline,
               allocator->tasks[i].assignedEmployeeId, allocator->tasks[i].isCompleted ? "Completed" : "Pending");
    }
}