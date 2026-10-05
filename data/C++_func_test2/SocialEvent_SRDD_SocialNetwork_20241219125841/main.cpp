int main() {
    EventManager eventManager;
    vector<User> users;
    PhotoGallery gallery;
    Discussion discussion("General Discussion");
    cout << "Welcome to SocialEvent!" << endl;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1: {
                string name, email, bio, location;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter email: ";
                getline(cin, email);
                cout << "Enter bio: ";
                getline(cin, bio);
                cout << "Enter location: ";
                getline(cin, location);
                User newUser(name, email);
                newUser.createProfile(bio, location);
                users.push_back(newUser);
                cout << "User profile created successfully!" << endl;
                break;
            }
            case 2: {
                cout << "\n--- User Profiles ---" << endl;
                for (int i = 0; i < users.size(); i++) {
                    cout << "User " << i + 1 << ":" << endl;
                    users[i].displayProfile();
                }
                break;
            }
            case 3: {
                string name, location, date;
                cout << "Enter event name: ";
                getline(cin, name);
                cout << "Enter event location: ";
                getline(cin, location);
                cout << "Enter event date (YYYY-MM-DD): ";
                getline(cin, date);
                eventManager.createEvent(name, location, date);
                cout << "Event created successfully!" << endl;
                break;
            }
            case 4: {
                eventManager.listEvents();
                break;
            }
            case 5: {
                string eventName;
                cout << "Enter the name of the event to RSVP: ";
                getline(cin, eventName);
                Event* event = eventManager.findEvent(eventName);
                if (event) {
                    cout << "Enter your user index to RSVP (1 to " << users.size() << "): ";
                    int userIndex;
                    cin >> userIndex;
                    cin.ignore();
                    if (userIndex > 0 && userIndex <= users.size()) {
                        event->addAttendee(users[userIndex - 1]);
                        cout << "RSVP successful!" << endl;
                    } else {
                        cout << "Invalid user index!" << endl;
                    }
                } else {
                    cout << "Event not found!" << endl;
                }
                break;
            }
            case 6: {
                string eventName;
                cout << "Enter the name of the event to view details: ";
                getline(cin, eventName);
                Event* event = eventManager.findEvent(eventName);
                if (event) {
                    event->displayEventDetails();
                    event->displayAttendees();
                } else {
                    cout << "Event not found!" << endl;
                }
                break;
            }
            case 7: {
                string userName, message;
                cout << "Enter your name: ";
                getline(cin, userName);
                cout << "Enter your message: ";
                getline(cin, message);
                discussion.addMessage(userName, message);
                discussion.displayMessages();
                break;
            }
            case 8: {
                string photoPath;
                cout << "Enter photo path to add to the gallery: ";
                getline(cin, photoPath);
                gallery.addPhoto(photoPath);
                gallery.displayPhotos();
                break;
            }
            case 9: {
                cout << "Exiting SocialEvent. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
    } while (choice != 9);
    return 0;
}