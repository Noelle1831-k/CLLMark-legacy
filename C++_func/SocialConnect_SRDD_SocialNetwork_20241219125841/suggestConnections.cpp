void MatchMaker::suggestConnections(const User& user, const Network& network) {
    cout << "Suggested connections for " << user.getName() << ":\n";
    vector<User>& users = network.getUsers();
    for (int i = 0; i < users.size(); i++) {
        if (user.getName() != users[i].getName()) {
            int commonInterests = 0;
            for (int j = 0; j < user.getInterests().size(); j++) {
                if (find(users[i].getInterests().begin(), users[i].getInterests().end(), user.getInterests()[j]) != users[i].getInterests().end()) {
                    commonInterests++;
                }
            }
            int commonHobbies = 0;
            for (int j = 0; j < user.getHobbies().size(); j++) {
                if (find(users[i].getHobbies().begin(), users[i].getHobbies().end(), user.getHobbies()[j]) != users[i].getHobbies().end()) {
                    commonHobbies++;
                }
            }
            if (commonInterests > 0 || commonHobbies > 0) {
                cout << users[i].getName() << " (Common Interests: " << commonInterests << ", Common Hobbies: " << commonHobbies << ")\n";
            }
        }
    }
}