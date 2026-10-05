void deleteTicket() {
    int id;
    printf("Enter Ticket ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].id == id) {
            found = 1;
            for (int j = i; j < ticketCount - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            ticketCount--;
            printf("Ticket deleted successfully.\n");
            logActivity("Ticket deleted.");
            break;
        }
    }
    if (!found) {
        printf("Error: Ticket not found.\n");
    }
}