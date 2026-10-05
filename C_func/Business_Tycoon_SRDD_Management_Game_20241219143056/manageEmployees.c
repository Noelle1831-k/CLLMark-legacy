void manageEmployees() {
    printf("Managing employees...\n");
    for (int i = 0; i < totalEmployees; i++) {
        employees[i].performance += rand() % 10 - 5;  
        if (employees[i].performance < 0) {
            employees[i].performance = 0;
        }
        printf("Employee %s: Performance %d\n", employees[i].name, employees[i].performance);
    }
}