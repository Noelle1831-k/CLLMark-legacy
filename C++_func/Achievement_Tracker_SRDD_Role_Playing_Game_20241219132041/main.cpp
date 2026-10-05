int main() {
    AchievementManager manager;
    int choice = 0;
    while (choice != 6) {
        displayMainMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string name, description, category;
                cout << "Enter Achievement Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Description: ";
                getline(cin, description);
                cout << "Enter Category: ";
                getline(cin, category);
                manager.addAchievement(name, description, category);
                break;
            }
            case 2: {
                string name;
                cout << "Enter Achievement Name to Update: ";
                cin.ignore();
                getline(cin, name);
                manager.updateAchievement(name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter Achievement Name to Mark as Completed: ";
                cin.ignore();
                getline(cin, name);
                manager.markAchievementAsCompleted(name);
                break;
            }
            case 4: {
                manager.viewAllAchievements();
                break;
            }
            case 5: {
                string name;
                cout << "Enter Achievement Name to Set Reminder: ";
                cin.ignore();
                getline(cin, name);
                manager.setReminder(name);
                break;
            }
            case 6: {
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    return 0;
}