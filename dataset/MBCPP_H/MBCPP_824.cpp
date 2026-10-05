    vector<int> odd;
    for (int i=0; i<l.size(); i++) {
        if (l[i] % 2 != 0) {
            odd.push_back(l[i]);
        }
    }
    return odd;
}