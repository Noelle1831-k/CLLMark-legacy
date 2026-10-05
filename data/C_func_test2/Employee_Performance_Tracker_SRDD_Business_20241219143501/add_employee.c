void add_employee() {
    if ((MAX_EMPLOYEES < employee_count || MAX_EMPLOYEES == employee_count)) {
        printf("Cannot add more employees. Limit reached.\n");
        return;
    }
    Employee new_employee;
    new_employee.id = employee_count + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", new_employee.name);
    printf("Enter role: ");
    scanf(" %[^\n]", new_employee.role);
    employees[employee_count++] = new_employee;
    printf("Employee added successfully with ID %d!\n", new_employee.id);
}