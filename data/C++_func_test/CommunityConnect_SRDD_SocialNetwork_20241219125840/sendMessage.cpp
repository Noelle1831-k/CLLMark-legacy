void Messaging::sendMessage() {
    cout << "Enter Sender ID: ";
    cin >> senderID;
    cout << "Enter Receiver ID: ";
    cin >> receiverID;
    cout << "Enter Message: ";
    cin.ignore();
    getline(cin, messageContent);
    time_t now = time(0);
    timestamp = ctime(&now);
    cout << "Message sent successfully at " << timestamp << endl;
}