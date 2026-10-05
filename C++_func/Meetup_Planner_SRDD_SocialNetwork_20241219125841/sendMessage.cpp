void Messaging::sendMessage(const User& sender, const User& receiver, const string& message) const {
    cout << "Message from " << sender.getName() << " to " << receiver.getName() << ": " << message << endl;
}