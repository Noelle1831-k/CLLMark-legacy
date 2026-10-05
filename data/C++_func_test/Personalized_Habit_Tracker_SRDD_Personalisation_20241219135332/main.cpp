int main() {
    HabitTracker tracker;
    User user("John Doe");
    tracker.loadData(user);
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string name;
                int frequency;
                cout << "Enter habit name: ";
                cin >> name;
                cout << "Enter frequency (times per week): ";
                cin >> frequency;
                Habit habit(name, frequency);
                user.addHabit(habit);
                break;
            }
            case 2: {
                string name;
                cout << "Enter habit name to remove: ";
                cin >> name;
                user.removeHabit(name);
                break;
            }
            case 3:
                user.displayHabits();
                break;
            case 4: {
                string name;
                int progress;
                cout << "Enter habit name to update progress: ";
                cin >> name;
                cout << "Enter progress increment: ";
                cin >> progress;
                user.updateHabitProgress(name, progress);
                break;
            }
            case 5:
                user.getPersonalizedRecommendations();
                break;
            case 6:
                tracker.generateReport(user);
                break;
            case 7:
                tracker.saveData(user);
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}