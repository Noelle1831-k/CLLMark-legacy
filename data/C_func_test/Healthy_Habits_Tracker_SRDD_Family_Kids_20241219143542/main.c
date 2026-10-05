int main() {
    int choice;
    printf("Welcome to Healthy Habits Tracker!\n");
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createProfile(); break;
            case 2: setGoals(); break;
            case 3: trackProgress(); break;
            case 4: viewReports(); break;
            case 5: printf("Exiting the application...\n"); exit(0); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}