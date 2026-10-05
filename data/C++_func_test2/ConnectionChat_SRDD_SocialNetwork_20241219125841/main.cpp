int main() {
    cout << "Welcome to the Professional Networking Application!" << endl;
    User user1("Alice", "Software", "Developer", {"C++", "Python"}, "alice@example.com");
    User user2("Bob", "Software", "Tester", {"Java", "Automation"}, "bob@example.com");
    user1.displayProfile();
    user2.displayProfile();
    SearchEngine searchEngine;
    vector<User> results = searchEngine.searchByIndustry("Software", {user1, user2});
    cout << "Search Results by Industry: " << endl;
    for (size_t i = 0; i < results.size(); i++) {
        results[i].displayProfile();
    }
    ChatManager chatManager;
    chatManager.initiatePrivateChat(user1, user2);
    chatManager.sendMessage(user1, user2, "Hello Bob!");
    chatManager.receiveMessage(user2, user1, "Hi Alice!");
    FileSharing fileSharing;
    fileSharing.uploadFile(user1, "project.zip");
    fileSharing.downloadFile(user2, "project.zip");
    ConnectionManager connectionManager;
    connectionManager.addConnection(user1, user2);
    connectionManager.listConnections(user1);
    return 0;
}