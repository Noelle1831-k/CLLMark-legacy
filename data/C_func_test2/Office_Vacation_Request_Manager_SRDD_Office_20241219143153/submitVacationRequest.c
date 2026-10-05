void submitVacationRequest() {
    VacationRequest request;
    printf("Submitting vacation request...\n");
    printf("Enter Employee Name: ");
    scanf("%s", request.employeeName);
    printf("Enter Start Date (YYYY-MM-DD): ");
    scanf("%s", request.startDate);
    printf("Enter End Date (YYYY-MM-DD): ");
    scanf("%s", request.endDate);
    strcpy(request.status, "Pending");
    request.requestId = generateRequestId();
    vacationRequests[requestCount++] = request;
    sendNotification("Request submitted.");
}