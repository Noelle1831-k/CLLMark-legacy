void distributeWorkload(TaskAllocator *allocator) {
    int totalWorkload = 0;
    for (int i = 0; i < allocator->employeeCount; i++) {
        totalWorkload += allocator->employees[i].workload;
    }
    int averageWorkload = totalWorkload / allocator->employeeCount;
    for (int i = 0; i < allocator->employeeCount; i++) {
        if (allocator->employees[i].workload > averageWorkload) {
            allocator->employees[i].workload = averageWorkload;
        }
    }
}