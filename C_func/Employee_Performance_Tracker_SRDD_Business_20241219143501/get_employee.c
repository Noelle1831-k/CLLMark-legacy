Employee* get_employee(int id) {
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            return &employees[i];
        }
    }
    printf("Employee with ID %d not found.\n", id);
    return NULL;
}