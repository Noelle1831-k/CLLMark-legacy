void set_performance_goals() {
    int id;
    printf("Enter Employee ID to set goals: ");
    scanf("%d", &id);
    Employee* emp = get_employee(id);
    if (emp == NULL) return;
    printf("Enter performance goals for %s: ", emp->name);
    scanf(" %[^\n]", performances[performance_count].goals);
    performances[performance_count].employee_id = id;
    performance_count++;
    printf("Performance goals set successfully!\n");
}