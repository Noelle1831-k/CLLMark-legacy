int main() {
    SocialNetwork app;
    int choice = 0;
    cout << "Welcome to SocialShare!" << endl;
    while (true) {
        cout << "\nMenu:\n1. Register\n2. Login\n3. Explore Content\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                app.registerUser();
                break;
            case 2:
                app.loginUser();
                break;
            case 3:
                app.exploreContent();
                break;
            case 4:
                cout << "Exiting SocialShare. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}