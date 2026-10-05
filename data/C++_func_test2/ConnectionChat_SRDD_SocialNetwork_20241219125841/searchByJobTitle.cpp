vector<User> SearchEngine::searchByJobTitle(string jobTitle, vector<User> users) {
    vector<User> results;
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getJobTitle() == jobTitle) {
            results.push_back(users[i]);
        }
    }
    return results;
}