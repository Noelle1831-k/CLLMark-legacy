vector<User> SearchEngine::searchBySkills(string skill, vector<User> users) {
    vector<User> results;
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].hasSkill(skill)) {
            results.push_back(users[i]);
        }
    }
    return results;
}