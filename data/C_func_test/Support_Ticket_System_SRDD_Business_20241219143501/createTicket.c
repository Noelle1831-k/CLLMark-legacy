void createTicket() {
    if (ticketCount >= MAX_TICKETS) {
        printf("Error: Ticket limit reached.\n");
        return;
    }
    Ticket newTicket;
    newTicket.id = ticketCount + 1;
    printf("Enter ticket description: ");
    scanf(" %[^\n]", newTicket.description);
    strcpy(newTicket.status, "Open");
    strcpy(newTicket.assignedAgent, "Unassigned");
    newTicket.priority = 1;
    tickets[ticketCount++] = newTicket;
    printf("Ticket created successfully! Ticket ID: %d\n", newTicket.id);
    logActivity("New ticket created.");
}