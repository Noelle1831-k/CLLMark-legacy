void assignTask(TaskAllocator *allocator) {
    for (int i = 0; i < allocator->taskCount; i++) {
        int minWorkload = INT_MAX;
        int bestEmployeeIndex = -1;
        for (int j = 0; j < allocator->employeeCount; j++) {
            if (allocator->employees[j].workload < minWorkload) {
                minWorkload = allocator->employees[j].workload;
                bestEmployeeIndex = j;
            }
        }
        if (bestEmployeeIndex != -1) {
            allocator->tasks[i].assignedEmployeeId = allocator->employees[bestEmployeeIndex].id;
            allocator->employees[bestEmployeeIndex].workload++;
        }
    }
}