void listTickets() {
    if (ticketCount == 0) {
        printf("No tickets available.\n");
        return;
    }
    printf("\n--- List of Tickets ---\n");
    for (int i = 0; i < ticketCount; i++) {
        printf("ID: %d | Description: %s | Status: %s | Assigned Agent: %s | Priority: %d\n",
               tickets[i].id, tickets[i].description, tickets[i].status, tickets[i].assignedAgent, tickets[i].priority);
    }
    logActivity("Tickets listed.");
}