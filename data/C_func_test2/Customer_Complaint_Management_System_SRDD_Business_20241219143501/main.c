int main() {
    int choice;
    initializeSystem();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                submitComplaint();
                break;
            case 2:
                trackComplaint();
                break;
            case 3:
                assignComplaint();
                break;
            case 4:
                escalateComplaint();
                break;
            case 5:
                generateReport();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}