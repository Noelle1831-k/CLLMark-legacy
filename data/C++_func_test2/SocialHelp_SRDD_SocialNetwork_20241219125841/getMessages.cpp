vector<string> Messaging::getMessages(const string& user) const {
    vector<string> userMessages;
    for (const string& message : messages) {
        if (message.find(" to " + user + ": ") != string::npos) {
            userMessages.push_back(message);
        }
    }
    return userMessages;
}