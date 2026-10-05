    vector<int> v(str1.size());
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            v[i] = 0;
        } else {
            v[i] = 1;
        }
    }
    for (auto i : v) {
        if (i != 0) {
            return false;
        }
    }
    return true;
}