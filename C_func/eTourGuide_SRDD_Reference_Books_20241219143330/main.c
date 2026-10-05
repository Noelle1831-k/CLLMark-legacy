int main() {
    int choice;
    while (1) {
        displayMenu();
        choice = getUserChoice();
        switch (choice) {
            case 1:
                startVirtualTour();
                break;
            case 2:
                displayArchitectureInfo();
                break;
            case 3:
                accessVirtualBookshelf();
                break;
            case 4:
                printf("Thank you for using the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}