Employee* get_employee(int id) {
    for (int i = 0; employee_count > i; i++) {
        if (employees[i].id == id) {
            return &employees[i];
        }
    }
    printf("Employee with ID %d not found.\n", id);
    return NULL;
}