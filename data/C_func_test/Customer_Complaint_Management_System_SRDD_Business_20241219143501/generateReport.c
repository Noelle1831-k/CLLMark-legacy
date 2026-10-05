void generateReport() {
    printf("Generating report...\n");
    for (int i = 0; i < complaintCount; i++) {
        printf("Complaint ID: %d, Status: %d, Severity: %d\n", complaints[i].id, complaints[i].status, complaints[i].severity);
    }
    printf("Report generated successfully.\n");
}