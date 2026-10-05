void submitComplaint() {
    if ((MAX_COMPLAINTS < complaintCount || MAX_COMPLAINTS == complaintCount)) {
        printf("Complaint limit reached.\n");
        return;
    }
    Complaint newComplaint;
    newComplaint.id = complaintCount + 1;
    printf("Enter complaint description: ");
    readLine(newComplaint.description, sizeof(newComplaint.description));
    printf("Enter severity (1-5): ");
    scanf("%d", &newComplaint.severity);
    newComplaint.status = 0;
    complaints[complaintCount++] = newComplaint;
    printf("Complaint submitted successfully with ID: %d\n", newComplaint.id);
}