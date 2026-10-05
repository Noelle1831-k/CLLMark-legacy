void evaluate_performance() {
    int id;
    printf("Enter Employee ID to evaluate: ");
    scanf("%d", &id);
    Employee* emp = get_employee(id);
    if (emp == NULL) return;
    for (int i = 0; i < performance_count; i++) {
        if (performances[i].employee_id == id) {
            printf("Enter evaluation for %s: ", emp->name);
            scanf(" %[^\n]", performances[i].evaluation);
            printf("Performance evaluation saved!\n");
            return;
        }
    }
    printf("No goals set for this employee.\n");
}