void runApp() {
    int choice;
    int running = 1;
    while (running) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                createFamily();
                break;
            case 3:
                createChallenge();
                break;
            case 4:
                trackProgress();
                trackFamilyProgress();
                break;
            case 5:
                displayRewards();
                break;
            case 6:
                playTutorial();
                break;
            case 7:
                sendMotivation();
                break;
            case 8:
                printf("Exiting FamilyFitnessFun. Stay active and healthy!\n");
                running = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}