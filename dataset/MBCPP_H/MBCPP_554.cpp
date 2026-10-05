    vector<int> result = {};
    for (int i = 0; i < list.size(); i++) {
        if (list[i] % 2 == 1) {
            result.push_back(list[i]);
        }
    }
    return result;
}