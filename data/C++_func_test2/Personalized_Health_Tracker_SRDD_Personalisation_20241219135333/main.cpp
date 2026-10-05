int main() {
    User user;
    HealthTracker tracker;
    Nutrition nutrition;
    Activity activity;
    int choice;
    cout << "Welcome to the Health Tracking Application!" << endl;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Input User Data" << endl;
        cout << "2. Display User Data" << endl;
        cout << "3. Set Health Goals" << endl;
        cout << "4. Track Progress" << endl;
        cout << "5. Generate Recommendations" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }
        switch (choice) {
            case 1:
                user.setUserData();
                break;
            case 2:
                user.displayUserData();
                break;
            case 3:
                tracker.setGoals();
                break;
            case 4:
                tracker.trackProgress(user);
                break;
            case 5:
                tracker.generateRecommendations(user, nutrition, activity);
                break;
            case 6:
                cout << "Exiting the application. Stay healthy!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}