vector<User> User::searchUsers(vector<User> users, string interest) {
    vector<User> matchedUsers;
    for (int i = 0; i < users.size(); i++) {
        for (int j = 0; j < users[i].interests.size(); j++) {
            if (users[i].interests[j] == interest) {
                matchedUsers.push_back(users[i]);
                break;
            }
        }
    }
    return matchedUsers;
}