    vector<int> result = vector<int>(0);
    for (int i = 0; i < l1.size(); i++) {
        if (l1[i] == l2[i] && l1[i] == l3[i]) {
            result.push_back(l1[i]);
        }
    }
    return result;
}