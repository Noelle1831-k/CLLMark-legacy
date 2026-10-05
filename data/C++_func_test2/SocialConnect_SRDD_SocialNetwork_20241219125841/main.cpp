int main() {
    Network network;
    MatchMaker matchMaker;
    cout << "Welcome to the Networking Application!" << endl;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add User\n";
        cout << "2. Display All Users\n";
        cout << "3. Find Matches\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string name;
            int age;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            User newUser(name, age);
            int numInterests, numHobbies;
            cout << "Enter number of interests: ";
            cin >> numInterests;
            for (int i = 0; i < numInterests; i++) {
                string interest;
                cout << "Enter interest " << i + 1 << ": ";
                cin >> interest;
                newUser.addInterest(interest);
            }
            cout << "Enter number of hobbies: ";
            cin >> numHobbies;
            for (int i = 0; i < numHobbies; i++) {
                string hobby;
                cout << "Enter hobby " << i + 1 << ": ";
                cin >> hobby;
                newUser.addHobby(hobby);
            }
            network.addUser(newUser);
        } else if (choice == 2) {
            network.displayAllUsers();
        } else if (choice == 3) {
            string name;
            cout << "Enter the name of the user to find matches for: ";
            cin >> name;
            User* user = network.getUserByName(name);
            if (user) {
                matchMaker.suggestConnections(*user, network);
            } else {
                cout << "User not found!" << endl;
            }
        } else if (choice == 4) {
            cout << "Exiting the application. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}