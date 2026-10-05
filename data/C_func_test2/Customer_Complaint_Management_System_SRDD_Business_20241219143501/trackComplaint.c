void trackComplaint() {
    int id;
    printf("Enter complaint ID to track: ");
    scanf("%d", &id);
    for (int i = 0; i < complaintCount; i++) {
        if (complaints[i].id == id) {
            printf("Complaint ID: %d\n", complaints[i].id);
            printf("Description: %s\n", complaints[i].description);
            printf("Severity: %d\n", complaints[i].severity);
            printf("Status: %d\n", complaints[i].status);
            return;
        }
    }
    printf("Complaint not found.\n");
}