void approveRejectRequest() {
    int requestId;
    char decision[10];
    printf("Approving/Rejecting request...\n");
    printf("Enter Request ID: ");
    scanf("%d", &requestId);
    printf("Enter Decision (Approve/Reject): ");
    scanf("%s", decision);
    for (int i = 0; i < requestCount; i++) {
        if (vacationRequests[i].requestId == requestId) {
            strcpy(vacationRequests[i].status, decision);
            sendNotification("Request processed.");
            return;
        }
    }
    printf("Request not found.\n");
}