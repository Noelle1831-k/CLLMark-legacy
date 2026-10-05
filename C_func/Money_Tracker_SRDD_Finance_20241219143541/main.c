int main() {
    int choice;
    while (1) {
        displayMenu();
        choice = getValidatedInput();
        switch (choice) {
            case 1:
                manageData();
                break;
            case 2:
                visualizeData();
                break;
            case 3:
                manageBudget();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}