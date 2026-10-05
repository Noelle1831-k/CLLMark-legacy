void Collaboration::sendMessage(User sender, User receiver, string message) {
    cout << sender.getUserName() << " sends message to " << receiver.getUserName() << ": " << message << endl;
}