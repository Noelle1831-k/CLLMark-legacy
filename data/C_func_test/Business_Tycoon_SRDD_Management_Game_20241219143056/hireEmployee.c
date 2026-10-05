void hireEmployee() {
    if (gameBusiness.cash < 3000) {
        printf("Not enough cash to hire an employee.\n");
        return;
    }
    if (totalEmployees < MAX_EMPLOYEES) {
        printf("Hiring employee...\n");
        printf("Enter employee name: ");
        scanf("%s", employees[totalEmployees].name);
        employees[totalEmployees].salary = 3000;  
        employees[totalEmployees].performance = 70;  
        totalEmployees++;
        gameBusiness.cash -= 3000;  
        gameBusiness.employees = totalEmployees;
        printf("Employee %s hired!\n", employees[totalEmployees - 1].name);
    } else {
        printf("Maximum employee limit reached!\n");
    }
}