void handleUserInput() {
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            submitVacationRequest();
            break;
        case 2:
            checkRequestStatus();
            break;
        case 3:
            viewRequests();
            break;
        case 4:
            approveRejectRequest();
            break;
        case 5:
            generateReport();
            break;
        case 6:
            saveData();
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}