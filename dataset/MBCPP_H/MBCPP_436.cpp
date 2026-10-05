    vector<int> result = {};
    for (int i = 0; i < list1.size(); i++) {
        if (list1[i] < 0) {
            result.push_back(list1[i]);
        }
    }
    return result;
}