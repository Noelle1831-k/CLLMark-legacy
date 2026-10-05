    vector<int> res = {0, 0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            res[0] += 1;
        } else if (s[i] >= '0' && s[i] <= '9') {
            res[1] += 1;
        }
    }
    return res;
}