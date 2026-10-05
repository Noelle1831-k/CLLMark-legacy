    vector<string> result = vector<string>();
    for (int i = 0; i < list1.size(); i++) {
        if (list1[i] != removewords[0] && list1[i] != removewords[removewords.size() - 1]) {
            result.push_back(list1[i]);
        }
    }
    return result;
}