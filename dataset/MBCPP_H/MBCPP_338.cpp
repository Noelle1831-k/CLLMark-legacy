    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                count++;
            }
        }
    }
    return count;
}