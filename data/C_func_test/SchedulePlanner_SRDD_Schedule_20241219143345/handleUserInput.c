void handleUserInput() {
    int choice;
    scanf("%d", &choice);
    getchar();  
    switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            viewSchedule();
            break;
        case 3:
            setReminder();
            break;
        case 4:
            generateReport();
            break;
        case 5:
            printf("Exiting SchedulePlanner. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}