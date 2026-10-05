void escalateComplaint() {
    int complaintId;
    printf("Enter complaint ID to escalate: ");
    scanf("%d", &complaintId);
    for (int i = 0; i < complaintCount; i++) {
        if (complaints[i].id == complaintId) {
            if (complaints[i].severity < 5) {
                complaints[i].severity++;
                printf("Complaint severity increased to %d.\n", complaints[i].severity);
            } else {
                printf("Complaint already at maximum severity.\n");
            }
            return;
        }
    }
    printf("Complaint not found.\n");
}