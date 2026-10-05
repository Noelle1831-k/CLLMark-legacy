void Conversation::startChat() {
    cout << "Starting chat between " << user1 << " and " << user2 << "." << endl;
    string message;
    while (true) {
        cout << "Enter message (or 'exit' to end chat): ";
        cin.ignore();
        getline(cin, message);
        if (message == "exit") {
            break;
        }
        addMessage(message);
    }
    viewChat();
}