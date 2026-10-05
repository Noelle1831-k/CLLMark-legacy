int main() {
    cout << "Welcome to the Learning Network Application!" << endl;
    vector<User> users;
    vector<StudyGroup> groups;
    vector<Resource> resources;
    vector<Webinar> webinars;
    vector<Discussion> discussions;
    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Create User Profile\n";
        cout << "2. Create Study Group\n";
        cout << "3. Share Educational Resource\n";
        cout << "4. Schedule Webinar\n";
        cout << "5. Start Discussion\n";
        cout << "6. Display All Users\n";
        cout << "7. Display All Study Groups\n";
        cout << "8. Display All Resources\n";
        cout << "9. Display All Webinars\n";
        cout << "10. Display All Discussions\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                User newUser;
                newUser.createProfile();
                users.push_back(newUser);
                break;
            }
            case 2: {
                StudyGroup newGroup;
                newGroup.createGroup();
                groups.push_back(newGroup);
                break;
            }
            case 3: {
                Resource newResource;
                newResource.addResource();
                resources.push_back(newResource);
                break;
            }
            case 4: {
                Webinar newWebinar;
                newWebinar.scheduleWebinar();
                webinars.push_back(newWebinar);
                break;
            }
            case 5: {
                Discussion newDiscussion;
                newDiscussion.startDiscussion();
                discussions.push_back(newDiscussion);
                break;
            }
            case 6: {
                cout << "\nDisplaying All Users:\n";
                for (int i = 0; i < users.size(); i++) {
                    cout << "User " << i + 1 << ":\n";
                    users[i].displayProfile();
                }
                break;
            }
            case 7: {
                cout << "\nDisplaying All Study Groups:\n";
                for (int i = 0; i < groups.size(); i++) {
                    cout << "Group " << i + 1 << ":\n";
                    groups[i].displayGroup();
                }
                break;
            }
            case 8: {
                cout << "\nDisplaying All Resources:\n";
                for (int i = 0; i < resources.size(); i++) {
                    cout << "Resource " << i + 1 << ":\n";
                    resources[i].displayResource();
                }
                break;
            }
            case 9: {
                cout << "\nDisplaying All Webinars:\n";
                for (int i = 0; i < webinars.size(); i++) {
                    cout << "Webinar " << i + 1 << ":\n";
                    webinars[i].displayWebinar();
                }
                break;
            }
            case 10: {
                cout << "\nDisplaying All Discussions:\n";
                for (int i = 0; i < discussions.size(); i++) {
                    cout << "Discussion " << i + 1 << ":\n";
                    discussions[i].displayDiscussion();
                }
                break;
            }
            case 11:
                cout << "Exiting application. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}