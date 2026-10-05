void Conversation::viewChat() const {
    cout << "Chat between " << user1 << " and " << user2 << ":" << endl;
    for (size_t i = 0; i < messages.size(); i++) {
        cout << messages[i] << endl;
    }
}