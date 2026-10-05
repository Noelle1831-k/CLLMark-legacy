    vector<int> result = {};
    for (int i = 0; i < list.size(); i++) {
        if (i % n == 0) {
            result.push_back(list[i]);
        }
    }
    return result;
}