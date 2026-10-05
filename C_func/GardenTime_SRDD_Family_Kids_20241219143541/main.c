int main() {
    int choice;
    while (1) {
        printMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        switch (choice) {
            case 1:
                identifyPlant();
                break;
            case 2:
                showGardeningTutorials();
                break;
            case 3:
                showSoilPreparationTips();
                break;
            case 4:
                showWateringSchedule();
                break;
            case 5:
                takeQuiz();
                break;
            case 6:
                printf("Thank you for using GardenTime! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}