int main() {
    SocialMatchup app;
    int choice;
    while (true) {
        cout << "\nWelcome to SocialMatchup!" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Find Matches" << endl;
        cout << "3. Start Conversation" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            app.registerUser();
        } else if (choice == 2) {
            app.findMatches();
        } else if (choice == 3) {
            app.startConversation();
        } else if (choice == 4) {
            cout << "Exiting SocialMatchup. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}