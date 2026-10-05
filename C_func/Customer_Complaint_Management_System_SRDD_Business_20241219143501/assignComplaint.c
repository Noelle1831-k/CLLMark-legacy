void assignComplaint() {
    int complaintId, agentId;
    printf("Enter complaint ID to assign: ");
    scanf("%d", &complaintId);
    printf("Enter agent ID to assign to: ");
    scanf("%d", &agentId);
    for (int i = 0; i < complaintCount; i++) {
        if (complaints[i].id == complaintId) {
            complaints[i].assignedAgentId = agentId;
            complaints[i].status = 1; 
            printf("Complaint assigned to agent %d.\n", agentId);
            return;
        }
    }
    printf("Complaint not found.\n");
}