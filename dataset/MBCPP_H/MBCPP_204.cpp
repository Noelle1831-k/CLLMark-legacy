    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c[0]) {
            count++;
        }
    }
    return count;
}