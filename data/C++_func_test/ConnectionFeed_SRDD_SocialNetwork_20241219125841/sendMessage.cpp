void User::sendMessage(User& receiver, const string& content) {
    Message message(content, *this, receiver);
    receiver.receiveMessage(message);
}