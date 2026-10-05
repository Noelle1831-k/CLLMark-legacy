void load_data_from_file() {
    FILE* emp_file = fopen("employees.dat", "rb");
    FILE* perf_file = fopen("performances.dat", "rb");
    employee_count = 0; 
    performance_count = 0; 
    if (emp_file) {
        fread(&employee_count, sizeof(int), 1, emp_file);
        fread(employees, sizeof(Employee), employee_count, emp_file);
        fclose(emp_file);
    }
    if (perf_file) {
        fread(&performance_count, sizeof(int), 1, perf_file);
        fread(performances, sizeof(Performance), performance_count, perf_file);
        fclose(perf_file);
    }
}