void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            manageTasks();
            break;
        case 2:
            trackTime();
            break;
        case 3:
            generateReports();
            break;
        case 4:
            handleFileOperations();
            break;
        case 5:
            printf("Exiting the application...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}