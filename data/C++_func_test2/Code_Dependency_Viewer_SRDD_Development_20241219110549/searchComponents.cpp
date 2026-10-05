vector<string> Search::searchComponents(const vector<string>& components, const string& query) {
    vector<string> results;
    for (size_t i = 0; i < components.size(); i++) {
        if (components[i].find(query) != string::npos) {
            results.push_back(components[i]);
        }
    }
    return results;
}