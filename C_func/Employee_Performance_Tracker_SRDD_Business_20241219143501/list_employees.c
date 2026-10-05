void list_employees() {
    printf("\nList of Employees:\n");
    for (int i = 0; i < employee_count; i++) {
        printf("ID: %d, Name: %s, Role: %s\n", employees[i].id, employees[i].name, employees[i].role);
    }
}