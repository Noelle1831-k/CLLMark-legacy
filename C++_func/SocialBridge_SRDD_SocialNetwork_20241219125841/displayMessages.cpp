void Messaging::displayMessages() {
    cout << "Displaying all messages:" << endl;
    for (int i = 0; i < messages.size(); i++) {
        cout << "Message " << i + 1 << ": " << messages[i] << endl;
    }
}