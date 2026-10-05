int main() {
    srand(static_cast<unsigned int>(time(0)));
    SocialQuestApp app;
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string username, email, profilePicture;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter profile picture URL: ";
                cin >> profilePicture;
                app.registerUser(username, email, profilePicture);
                break;
            }
            case 2: {
                string username;
                cout << "Enter username: ";
                cin >> username;
                app.loginUser(username);
                break;
            }
            case 3:
                app.listHunts();
                break;
            case 4: {
                string huntName;
                cout << "Enter hunt name: ";
                cin >> huntName;
                app.participateInHunt(huntName);
                break;
            }
            case 5: {
                string huntName;
                cout << "Enter hunt name: ";
                cin >> huntName;
                app.createHunt(huntName);
                break;
            }
            case 6: {
                string huntName, description, clue, location;
                cout << "Enter hunt name: ";
                cin >> huntName;
                cout << "Enter challenge description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter challenge clue: ";
                getline(cin, clue);
                cout << "Enter challenge location: ";
                getline(cin, location);
                app.addChallengeToHunt(huntName, description, clue, location);
                break;
            }
            case 7: {
                string username, experience;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter experience: ";
                cin.ignore();
                getline(cin, experience);
                app.shareExperience(username, experience);
                break;
            }
            case 8:
                app.listExperiences();
                break;
            case 9:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);
    return 0;
}