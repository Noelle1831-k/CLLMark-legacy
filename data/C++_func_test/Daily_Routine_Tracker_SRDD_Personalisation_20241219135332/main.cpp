int main(void) {
    cout << "Welcome to the Personalization Software!\n";
    User user("John Doe");
    RecommendationEngine recommender;
    ReminderSystem reminders;
    ProgressTracker progressTracker;
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add a new habit\n";
        cout << "2. Record progress\n";
        cout << "3. View habits\n";
        cout << "4. Get recommendations\n";
        cout << "5. Generate progress report\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                string habitName;
                int targetTime;
                cout << "Enter habit name: ";
                scanf("%s", &habitName);
                cout << "Enter target time (in minutes): ";
                scanf("%d", &targetTime);
                user.addHabit(habitName, targetTime);
                reminders.sendReminder(habitName, "9:00 AM");
                break;
            }
            case 2: {
                string habitName;
                int completedTime;
                cout << "Enter habit name: ";
                scanf("%s", &habitName);
                cout << "Enter time completed today: ";
                scanf("%d", &completedTime);
                user.recordProgress(habitName, completedTime);
                break;
            }
            case 3:
                user.viewHabits();
                break;
            case 4:
                recommender.analyzeHabits(user.getHabits());
                break;
            case 5:
                progressTracker.generateReport();
                break;
            case 6:
                cout << "Thank you for using the software. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}