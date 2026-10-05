int main() {
    User user;
    GoalTracker tracker;
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            continue;
        }
        switch (choice) {
            case 1: {
                string name;
                double target;
                cout << "Enter goal name: ";
                cin.ignore();
                getline(cin, name);
                while (true) {
                    cout << "Enter target amount: ";
                    cin >> target;
                    if (cin.fail() || target <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid amount! Please enter a positive number." << endl;
                        continue;
                    }
                    break;
                }
                tracker.addGoal(user, name, target);
                break;
            }
            case 2: {
                tracker.displayGoals(user);
                break;
            }
            case 3: {
                tracker.updateProgress(user);
                break;
            }
            case 4: {
                tracker.setMilestones(user);
                break;
            }
            case 5: {
                cout << "Exiting application. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}