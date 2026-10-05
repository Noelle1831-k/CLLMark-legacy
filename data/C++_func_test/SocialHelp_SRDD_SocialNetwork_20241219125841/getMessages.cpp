vector<string> Messaging::getMessages(const string& user) const {
    vector<string> userMessages;
    for (const string& message : messages) {
        if (string::npos != message.find(" to " + user + ": ")) {
            userMessages.push_back(message);
        }
    }
    return userMessages;
}