int main(int argc, char *argv[]) {
    AppController* appController = new AppController(); 
    cout << "Welcome to Personalized Music Discovery!" << endl;
    while (true) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Add User Preferences\n";
        cout << "2. Get Recommendations\n";
        cout << "3. View All Preferences\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }
        switch (choice) {
            case 1:
                appController->addUserPreferences();
                break;
            case 2:
                appController->getRecommendations();
                break;
            case 3:
                appController->viewAllPreferences();
                break;
            case 4:
                cout << "Exiting the application. Thank you!" << endl;
                delete appController; 
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}