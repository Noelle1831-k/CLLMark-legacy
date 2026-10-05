Message::Message(const string& content, const User& sender, const User& receiver)
    : content(content), sender(sender), receiver(receiver) {
    time_t now = time(0);
    timestamp = ctime(&now);
}