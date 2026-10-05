int main() {
    Employee* employees = (Employee*)malloc(5 * sizeof(Employee));
    if (employees == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for employees.\n");
        return EXIT_FAILURE;
    }
    create_employee(&employees[0], 1, "Alice", "Developer", 8);
    create_employee(&employees[1], 2, "Bob", "Designer", 8);
    create_employee(&employees[2], 3, "Charlie", "Tester", 8);
    create_employee(&employees[3], 4, "David", "Manager", 8);
    create_employee(&employees[4], 5, "Eve", "Developer", 8);
    Task* tasks = (Task*)malloc(3 * sizeof(Task));
    if (tasks == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for tasks.\n");
        free(employees); 
        return EXIT_FAILURE;
    }
    create_task(&tasks[0], 1, "Develop feature A", "Developer");
    create_task(&tasks[1], 2, "Design UI for feature B", "Designer");
    create_task(&tasks[2], 3, "Test feature C", "Tester");
    Manager manager;
    manager.employees = employees;
    manager.num_employees = 5;
    assign_task(&manager, &tasks[0]);
    assign_task(&manager, &tasks[1]);
    assign_task(&manager, &tasks[2]);
    generate_report(&manager);
    WorkloadBalancer wb;
    wb.tasks = tasks;
    wb.num_tasks = 3;
    wb.employees = employees;
    wb.num_employees = 5;
    track_progress(&wb);
    balance_workload(&wb);
    free(employees);
    free(tasks);
    return 0;
}