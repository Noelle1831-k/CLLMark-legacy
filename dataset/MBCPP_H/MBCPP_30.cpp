    int len = s.size();
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (s[i] == s[j]) {
                count += 1;
            }
        }
    }
    return count;
}