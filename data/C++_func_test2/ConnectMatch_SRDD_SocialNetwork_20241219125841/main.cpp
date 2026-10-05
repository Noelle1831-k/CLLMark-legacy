int main() {
    ProfileManager profileManager;
    MatchingAlgorithm matcher;
    ConnectionManager connectionManager;
    User user1("Alice", {"C++", "Networking"}, {"Software Development"});
    User user2("Bob", {"Java", "Machine Learning"}, {"AI Research"});
    User user3("Charlie", {"Python", "Data Analysis"}, {"Data Science"});
    User user4("Diana", {"C++", "AI"}, {"Machine Learning", "Software Development"});
    profileManager.addUser(user1);
    profileManager.addUser(user2);
    profileManager.addUser(user3);
    profileManager.addUser(user4);
    vector<User> matches = matcher.findMatches(user1, profileManager.getAllUsers());
    cout << "Matches for " << user1.getName() << ":" << endl;
    for (int i = 0; i < matches.size(); i++) {
        cout << "- " << matches[i].getName() << endl;
    }
    connectionManager.connectUsers(user1, user2);
    connectionManager.connectUsers(user1, user3);
    connectionManager.connectUsers(user1, user4);
    connectionManager.displayConnections(user1);
    cout << "\nAll Users and Their Connections:" << endl;
    vector<User> allUsers = profileManager.getAllUsers();
    for (int i = 0; i < allUsers.size(); i++) {
        connectionManager.displayConnections(allUsers[i]);
    }
    return 0;
}