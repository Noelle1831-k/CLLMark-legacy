void generate_performance_report() {
    FILE *file = fopen("performance_report.txt", "w");
    if (!file) {
        printf("Error opening file for report generation.\n");
        return;
    }
    fprintf(file, "Performance Report\n");
    fprintf(file, "==================\n");
    for (int i = 0; i < performance_count; i++) {
        Employee* emp = get_employee(performances[i].employee_id);
        if (emp) {
            fprintf(file, "Employee: %s\n", emp->name);
            fprintf(file, "Goals: %s\n", performances[i].goals);
            fprintf(file, "Evaluation: %s\n\n", performances[i].evaluation);
        }
    }
    fclose(file);
    printf("Performance report generated and saved to 'performance_report.txt'.\n");
}