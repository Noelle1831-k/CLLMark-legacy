void checkRequestStatus() {
    int requestId;
    printf("Checking request status...\n");
    printf("Enter Request ID: ");
    scanf("%d", &requestId);
    for (int i = 0; i < requestCount; i++) {
        if (vacationRequests[i].requestId == requestId) {
            printf("Request ID: %d\n", vacationRequests[i].requestId);
            printf("Employee Name: %s\n", vacationRequests[i].employeeName);
            printf("Start Date: %s\n", vacationRequests[i].startDate);
            printf("End Date: %s\n", vacationRequests[i].endDate);
            printf("Status: %s\n", vacationRequests[i].status);
            return;
        }
    }
    printf("Request not found.\n");
}