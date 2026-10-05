    vector<int> result = vector<int>();
    for (int i = 0; i < list1.size(); i++) {
        if (i != l - 1) {
            result.push_back(list1[i]);
        }
    }
    return result;
}