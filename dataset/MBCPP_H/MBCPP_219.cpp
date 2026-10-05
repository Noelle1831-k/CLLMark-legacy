    vector<int> res;
    sort(testTup.begin(), testTup.end());
    vector<int> temp;
    for (int i = 0; i < testTup.size(); i++) {
        if (i < k || i >= testTup.size() - k) {
            res.push_back(testTup[i]);
        }
    }
    return res;
}