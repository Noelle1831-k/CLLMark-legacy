    vector<int> result = vector<int>();
    if (list1.size() == 0) {
        return result;
    }
    int min = list1[0];
    for (auto v : list1) {
        if (v < min) {
            min = v;
        }
    }
    for (int i = 0; i < list1.size(); i++) {
        if (list1[i] == min) {
            result.push_back(i);
        }
    }
    return result;
}