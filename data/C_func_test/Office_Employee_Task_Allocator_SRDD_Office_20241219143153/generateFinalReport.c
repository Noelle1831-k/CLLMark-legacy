void generateFinalReport(TaskAllocator *allocator) {
    printf("Final Report:\n");
    for (int i = 0; i < allocator->employeeCount; i++) {
        printf("Employee ID: %d, Name: %s, Workload: %d, Completed Tasks: %d\n",
               allocator->employees[i].id, allocator->employees[i].name,
               allocator->employees[i].workload, allocator->employees[i].completedTasks);
    }
}