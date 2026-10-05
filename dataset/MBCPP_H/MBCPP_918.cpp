    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= m) {
            result += n / s[i];
        }
        n %= s[i];
    }
    return result;
}