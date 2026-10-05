int main() {
    int choice;
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                exploreEcosystem();
                break;
            case 2:
                identifySpecies();
                break;
            case 3:
                startQuiz();
                break;
            case 4:
                playVideos();
                break;
            case 5:
                trackAdventure();
                break;
            case 6:
                printf("Thank you for using Nature Explorer. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}