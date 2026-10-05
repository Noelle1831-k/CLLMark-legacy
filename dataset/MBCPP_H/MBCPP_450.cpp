    vector<string> result = {};
    for (int i = 0; i < str.size(); i++) {
        if (str[i].size() == l) {
            result.push_back(str[i]);
        }
    }
    return result;
}