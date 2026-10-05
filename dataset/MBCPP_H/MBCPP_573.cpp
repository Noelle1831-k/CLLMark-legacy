    unordered_set<int> unique_set = unordered_set<int>();
    for (int i : listData) {
        unique_set.insert(i);
    }
    int product = 1;
    for (auto value : unique_set) {
        product *= value;
    }
    return product;
}