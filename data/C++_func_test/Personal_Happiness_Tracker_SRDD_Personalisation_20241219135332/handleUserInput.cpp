void handleUserInput(int choice) {
        switch (choice) {
        case 1:
            user->inputDailyData();
            break;
        case 2:
            user->displayUserData();
            analyzer.analyzeMoodTrends(user->getMoodHistory());
            analyzer.generateRecommendations(user->getActivityHistory());
            break;
        case 3:
            fileHandler.saveDataToFile("mood.txt", user->getMoodHistory());
            fileHandler.saveDataToFile("activities.txt", user->getActivityHistory());
            fileHandler.saveDataToFile("events.txt", user->getEventHistory());
            cout << "Data saved successfully!" << endl;
            break;
        case 4:
            cout << "Exiting the application. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }