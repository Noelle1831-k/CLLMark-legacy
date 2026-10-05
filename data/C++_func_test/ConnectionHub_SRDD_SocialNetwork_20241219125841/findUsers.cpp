vector<User> Search::findUsers(vector<User> &users, string query) {
    vector<User> results;
    for (auto &user : users) {
        if (user.getName().find(query) != string::npos) {
            results.push_back(user);
        }
    }
    return results;
}