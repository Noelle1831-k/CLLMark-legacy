void Messaging::sendMessage(string message) {
    messages.push_back(message);
    cout << "Message sent: " << message << endl;
}