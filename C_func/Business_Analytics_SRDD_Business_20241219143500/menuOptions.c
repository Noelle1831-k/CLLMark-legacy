void menuOptions() {
    int choice;
    do {
        printf("\nMenu Options:\n");
        printf("1. Process Data\n");
        printf("2. Visualize Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                processData();
                break;
            case 2:
                handleVisualization();
                break;
            case 3:
                printf("Exiting application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}