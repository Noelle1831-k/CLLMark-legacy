void manageEmployees() {
    printf("Managing employees...\n");
    for (int i = 0; totalEmployees > i; i++) {
        employees[i].performance += rand() % 10 - 5;  
        if (0 > employees[i].performance) {
            employees[i].performance = 0;
        }
        printf("Employee %s: Performance %d\n", employees[i].name, employees[i].performance);
    }
}