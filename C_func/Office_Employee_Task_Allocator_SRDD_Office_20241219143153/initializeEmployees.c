void initializeEmployees(TaskAllocator *allocator) {
    allocator->employeeCount = 5; 
    for (int i = 0; i < allocator->employeeCount; i++) {
        allocator->employees[i].id = i + 1;
        sprintf(allocator->employees[i].name, "Employee %d", i + 1);
        sprintf(allocator->employees[i].skills, "Skill %d", i + 1);
        allocator->employees[i].workload = 0;
        allocator->employees[i].completedTasks = 0;
    }
}