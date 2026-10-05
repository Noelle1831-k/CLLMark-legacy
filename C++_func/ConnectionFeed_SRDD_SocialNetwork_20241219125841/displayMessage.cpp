void Message::displayMessage() const {
    cout << "From: " << sender.getUsername() << " To: " << receiver.getUsername() << endl;
    cout << "Message: " << content << endl;
    cout << "Sent at: " << timestamp << endl;
}