int main() {
    initializeUI();
    AthleteList *athletes = createAthleteList();
    int choice;
    do {
        choice = displayMainMenu();
        switch (choice) {
            case 1:
                addNewAthlete(athletes);
                break;
            case 2:
                updatePerformanceMetrics(athletes);
                break;
            case 3:
                deleteAthlete(athletes);
                break;
            case 4:
                generatePerformanceReport(athletes);
                break;
            case 5:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    freeAthleteList(athletes);
    return 0;
}