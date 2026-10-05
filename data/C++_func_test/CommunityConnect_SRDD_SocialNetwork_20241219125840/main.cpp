int main() {
    vector<User> users;
    vector<Community> communities;
    vector<Event> events;
    vector<Messaging> messages;
    int choice;
    do {
        displayMenu();
        choice = getValidatedChoice();
        switch (choice) {
            case 1: {
                User newUser;
                newUser.createProfile();
                users.push_back(newUser);
                break;
            }
            case 2: {
                int userID;
                cout << "Enter User ID to update profile: ";
                while (!(cin >> userID)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid User ID: ";
                }
                bool found = false;
                for (auto &user : users) {
                    if (user.getUserID() == userID) {
                        user.updateProfile();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "User not found." << endl;
                }
                break;
            }
            case 3: {
                int userID;
                cout << "Enter User ID to view profile: ";
                while (!(cin >> userID)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid User ID: ";
                }
                bool found = false;
                for (const auto &user : users) {
                    if (user.getUserID() == userID) {
                        user.viewProfile();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "User not found." << endl;
                }
                break;
            }
            case 4: {
                Community newCommunity;
                newCommunity.addMember();
                communities.push_back(newCommunity);
                break;
            }
            case 5: {
                Event newEvent;
                newEvent.createEvent();
                events.push_back(newEvent);
                break;
            }
            case 6: {
                if (events.empty()) {
                    cout << "No events available." << endl;
                } else {
                    for (const auto &event : events) {
                        event.viewEvent();
                    }
                }
                break;
            }
            case 7: {
                Messaging newMessage;
                newMessage.sendMessage();
                messages.push_back(newMessage);
                break;
            }
            case 8: {
                if (messages.empty()) {
                    cout << "No messages available." << endl;
                } else {
                    for (const auto &message : messages) {
                        message.viewMessages();
                    }
                }
                break;
            }
            case 9:
                cout << "Exiting application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (! (choice == 9));
    return 0;
}