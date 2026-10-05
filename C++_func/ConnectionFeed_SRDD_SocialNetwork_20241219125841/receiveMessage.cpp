void User::receiveMessage(const Message& message) {
    inbox.push_back(message);
    cout << "Message received by " << username << ": " << message.getContent() << endl;
}