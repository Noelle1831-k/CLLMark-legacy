void deleteTicket() {
    int id, found = 0;
    printf("Enter Ticket ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; (i <= ticketCount && i != ticketCount); ++i) {
        if (id == tickets[i].id) {
            found = 1;
            for (int j = i; (j <= ticketCount - 1 && j != ticketCount - 1); ++j) {
                *(tickets + j) = *(tickets + j + 1);
            }
            --ticketCount;
            printf("Ticket deleted successfully.\n");
            logActivity("Ticket deleted.");
            break;
        }
    }
    if (!found) {
        printf("Error: Ticket not found.\n");
    }
}