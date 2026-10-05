int main() {
    PollManager pollManager;
    Network network;
    vector<User> users;
    string choice;
    cout << "Welcome to PollConnect!" << endl;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create Profile\n2. Create Poll\n3. View Polls\n4. Vote on Poll\n5. Show Results\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == "1") {
            string username;
            cout << "Enter username: ";
            cin >> username;
            User newUser(username);
            users.push_back(newUser);
            cout << "Profile created for user: " << username << endl;
        } else if (choice == "2") {
            if (users.empty()) {
                cout << "No users available. Create a profile first.\n";
                continue;
            }
            int userId;
            string pollTitle, option;
            vector<string> options;
            int duration;
            cout << "Enter your user ID: ";
            cin >> userId;
            if (userId < 0 || userId >= users.size()) {
                cout << "Invalid user ID.\n";
                continue;
            }
            cout << "Enter poll title: ";
            cin.ignore();
            getline(cin, pollTitle);
            cout << "Enter poll options (enter 'done' to stop): \n";
            while (true) {
                cin >> option;
                if (option == "done") break;
                options.push_back(option);
            }
            cout << "Enter poll duration (in minutes): ";
            cin >> duration;
            Poll newPoll = Poll::createPoll(users[userId], pollTitle, options, duration);
            pollManager.addPoll(newPoll);
            cout << "Poll created successfully!\n";
        } else if (choice == "3") {
            pollManager.displayPolls();
        } else if (choice == "4") {
            int pollId, userId, optionId;
            pollManager.displayPolls();
            cout << "Enter poll ID: ";
            cin >> pollId;
            Poll* poll = pollManager.findPollById(pollId);
            if (!poll) {
                cout << "Poll not found.\n";
                continue;
            }
            cout << "Enter your user ID: ";
            cin >> userId;
            if (userId < 0 || userId >= users.size()) {
                cout << "Invalid user ID.\n";
                continue;
            }
            cout << "Enter option number to vote: ";
            cin >> optionId;
            poll->vote(users[userId], optionId);
        } else if (choice == "5") {
            int pollId;
            cout << "Enter poll ID: ";
            cin >> pollId;
            Poll* poll = pollManager.findPollById(pollId);
            if (!poll) {
                cout << "Poll not found.\n";
                continue;
            }
            poll->showResults();
        } else if (choice == "6") {
            cout << "Exiting PollConnect. Thank you!\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}