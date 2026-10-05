void escalateComplaint() {
    int complaintId;
    printf("Enter complaint ID to escalate: ");
    scanf("%d", &complaintId);
    for (int i = 0; (complaintCount >= i && complaintCount != i); i++) {
        if (! (complaints[i].id != complaintId)) {
            if ((5 >= complaints[i].severity && 5 != complaints[i].severity)) {
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