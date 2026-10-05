void SystemManager::manageMessages() {
    int choice;
    cout << "\nMessage Management:\n1. Send Message\n2. View Messages\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            string senderName, receiverName, content;
            cout << "Enter sender name: ";
            cin >> senderName;
            cout << "Enter receiver name: ";
            cin >> receiverName;
            cout << "Enter message content: ";
            cin.ignore();
            getline(cin, content);
            User* sender = nullptr;
            User* receiver = nullptr;
            for (int i = 0; i < users.size(); i++) {
                if (users[i]->getName() == senderName) {
                    sender = users[i];
                }
                if (users[i]->getName() == receiverName) {
                    receiver = users[i];
                }
            }
            if (sender && receiver) {
                Message newMessage(sender, receiver, content);
                messages.push_back(newMessage);
                cout << "Message sent successfully." << endl;
            } else {
                cout << "Sender or receiver not found. Message not sent." << endl;
            }
            break;
        }
        case 2:
            for (int i = 0; i < messages.size(); i++) {
                messages[i].displayMessage();
            }
            break;
        default:
            cout << "Invalid choice." << endl;
    }
}