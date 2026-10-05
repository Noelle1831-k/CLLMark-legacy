void Dashboard::processChoice(int choice) {
    switch (choice) {
        case 1: {
            int ml;
            printf("Enter water intake in ml: ");
            cin >> ml;
            waterTracker.addIntake(ml);
            break;
        }
        case 2: {
            int goal;
            printf("Set your daily goal (ml): ");
            cin >> goal;
            waterTracker.setDailyGoal(goal);
            break;
        }
        case 3: {
            waterTracker.displaySummary();
            break;
        }
        case 4: {
            waterHistory.viewHistory();
            break;
        }
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}