void SocialMatchup::startConversation() {
    if (users.size() < 2) {
        cout << "Not enough users to start a conversation." << endl;
        return;
    }
    string user1, user2;
    cout << "Enter the name of the first user: ";
    cin >> user1;
    cout << "Enter the name of the second user: ";
    cin >> user2;
    Conversation convo(user1, user2);
    convo.startChat();
    conversations.push_back(convo);
}