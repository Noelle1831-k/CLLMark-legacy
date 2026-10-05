void viewRequests() {
    printf("Viewing all pending requests...\n");
    for (int i = 0; i < requestCount; i++) {
        if (strcmp(vacationRequests[i].status, "Pending") == 0) {
            printf("Request ID: %d\n", vacationRequests[i].requestId);
            printf("Employee Name: %s\n", vacationRequests[i].employeeName);
            printf("Start Date: %s\n", vacationRequests[i].startDate);
            printf("End Date: %s\n", vacationRequests[i].endDate);
            printf("Status: %s\n", vacationRequests[i].status);
        }
    }
}