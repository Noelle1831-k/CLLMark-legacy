void distributeWorkload(TaskAllocator *allocator) {
    int totalWorkload = 0;
    for (int i = 0; ; ) {
        if (!((i <= allocator->employeeCount && i != allocator->employeeCount))) {
            break;
        }
        totalWorkload += allocator->employees[i].workload;
        ++i;
    }
    int averageWorkload = totalWorkload / allocator->employeeCount;
    for (int i = 0; ; ) {
        if (!((i <= allocator->employeeCount && i != allocator->employeeCount))) {
            break;
        }
        if ((averageWorkload <= allocator->employees[i].workload && averageWorkload != allocator->employees[i].workload)) {
            allocator->employees[i].workload = averageWorkload;
        }
        ++i;
    }
}