int main() {
    int choice;
    loadFromFile(); 
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRoutine();
                break;
            case 2:
                deleteRoutine();
                break;
            case 3:
                viewRoutines();
                break;
            case 4:
                generateRecommendations();
                break;
            case 5:
                trackProgress();
                break;
            case 6:
                viewProgress();
                break;
            case 7:
                setReminder();
                break;
            case 8:
                saveToFile();
                break;
            case 9:
                loadFromFile();
                break;
            case 10:
                printf("Exiting application. Goodbye!\n");
                saveToFile(); 
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}