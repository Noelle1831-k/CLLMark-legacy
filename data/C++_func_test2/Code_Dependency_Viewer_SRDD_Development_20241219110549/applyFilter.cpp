vector<string> Filter::applyFilter(const vector<string>& components, const string& criteria) {
    vector<string> filtered;
    for (size_t i = 0; i < components.size(); i++) {
        if (components[i].find(criteria) != string::npos) {
            filtered.push_back(components[i]);
        }
    }
    return filtered;
}