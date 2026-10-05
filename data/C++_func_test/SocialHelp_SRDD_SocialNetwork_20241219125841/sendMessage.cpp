void Messaging::sendMessage(const string& from, const string& to, const string& message) {
    string timestamp = getCurrentTimestamp();
    string fullMessage = "[" + timestamp + "] " + from + " to " + to + ": " + message;
    messages.push_back(fullMessage);
}