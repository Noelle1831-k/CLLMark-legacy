    int i;
    vector<int> result = vector<int>(n);
    std::sort(list1.begin(), list1.end());
    for (i = 0; i < n; i++) {
        result[i] = list1[list1.size() - i - 1];
    }
    return result;
}