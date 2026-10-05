vector<User> SearchEngine::searchByIndustry(string industry, vector<User> users) {
    vector<User> results;
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getIndustry() == industry) {
            results.push_back(users[i]);
        }
    }
    return results;
}