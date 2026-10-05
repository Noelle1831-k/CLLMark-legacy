vector<string> Utility::splitText(const string& text, char delimiter) {
    vector<string> result;
    stringstream ss(text);
    string item;
    while (getline(ss, item, delimiter)) {
        if (!item.empty()) {
            result.push_back(item);
        }
    }
    return result;
}