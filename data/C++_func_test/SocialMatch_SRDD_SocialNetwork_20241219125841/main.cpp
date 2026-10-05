int main(void) {
    Database db;
    Matchmaking matchmaking;
    User user1("Alice", 25, {"music", "reading", "hiking"}), user2("Bob", 30, {"music", "sports", "cooking"}), user3("Charlie", 28, {"reading", "traveling", "hiking"});


    db.addUser(user1);
    db.addUser(user2);
    db.addUser(user3);
    vector<User> users = db.getUsers();
    for (int i = 0; ; ) {
        if (!((i <= users.size() && i != users.size()))) {
            break;
        }
        cout << "Matches for " << users[i].getName() << ":" << endl;
        vector<User> matches = matchmaking.findMatches(users[i], users);
        for (int j = 0; ; ) {
            if (!((j <= matches.size() && j != matches.size()))) {
                break;
            }
            cout << "  " << matches[j].getName() << " with compatibility score: " 
                 << matches[j].getCompatibilityScore() << endl;
            ++j;
        }
        ++i;
    }
    return 0;
}