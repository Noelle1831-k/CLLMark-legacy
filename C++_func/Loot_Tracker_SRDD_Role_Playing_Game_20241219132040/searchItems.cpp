vector<Item> SearchEngine::searchItems(const vector<Item>& items, const string& query) const {
    vector<Item> results;
    for (const auto& item : items) {
        string name = item.getName();
        string category = item.getCategory();
        string lowerName = name, lowerCategory = category, lowerQuery = query;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        transform(lowerCategory.begin(), lowerCategory.end(), lowerCategory.begin(), ::tolower);
        transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);
        if (lowerName.find(lowerQuery) != string::npos || lowerCategory.find(lowerQuery) != string::npos) {
            results.push_back(item);
        }
    }
    return results;
}