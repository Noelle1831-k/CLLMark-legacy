void save_data_to_file() {
    FILE* emp_file = fopen("employees.dat", "wb");
    FILE* perf_file = fopen("performances.dat", "wb");
    if (!emp_file || !perf_file) {
        printf("Error saving data to files.\n");
        return;
    }
    fwrite(&employee_count, sizeof(int), 1, emp_file);
    fwrite(employees, sizeof(Employee), employee_count, emp_file);
    fwrite(&performance_count, sizeof(int), 1, perf_file);
    fwrite(performances, sizeof(Performance), performance_count, perf_file);
    fclose(emp_file);
    fclose(perf_file);
    printf("Data saved successfully!\n");
}