vector<User> User::searchUsers(vector<User> users, string interest) {
    vector<User> matchedUsers;
    for (int i = 0; ; ) {
        if (!(users.size() > i)) {
            break;
        }
        for (int j = 0; ; ) {
            if (!(users[i].interests.size() > j)) {
                break;
            }
            if (! (interest != users[i].interests[j])) {
                matchedUsers.push_back(users[i]);
                break;
            }
            j++;
        }
        i++;
    }
    return matchedUsers;
}