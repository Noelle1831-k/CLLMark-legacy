void generate_report() {
    log_message("Generating report...");
    FILE *report_file = fopen("user_report.txt", "w");
    if (report_file == NULL) {
        log_message("Error: Could not open report file.");
        return;
    }
    fprintf(report_file, "User Data Report\n");
    fprintf(report_file, "================\n");
    for (int i = 0; i < user_count; i++) {
        fprintf(report_file, "Name: %s, Age: %d, Occupation: %s, Active Hours: %d\n",
                users[i].name, users[i].age, users[i].occupation, users[i].daily_active_hours);
    }
    fclose(report_file);
    log_message("Report generated successfully.");
}