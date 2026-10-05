int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createTicket();
                break;
            case 2:
                deleteTicket();
                break;
            case 3:
                listTickets();
                break;
            case 4:
                assignTicketToAgent();
                break;
            case 5:
                removeTicketFromAgent();
                break;
            case 6:
                setTicketPriority();
                break;
            case 7:
                generateReport();
                break;
            case 8:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}