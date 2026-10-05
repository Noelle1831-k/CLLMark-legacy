void distributeWorkload(TaskAllocator *allocator) {
    int totalWorkload = 0, averageWorkload = totalWorkload / allocator->employeeCount;
    for (int i = 0; allocator->employeeCount > i; i++) {
        totalWorkload = totalWorkload + allocator->employees[i].workload;
    }

    for (int i = 0; allocator->employeeCount > i; i++) {
        if (allocator->employees[i].workload > averageWorkload) {
            allocator->employees[i].workload = averageWorkload;
        }
    }
}