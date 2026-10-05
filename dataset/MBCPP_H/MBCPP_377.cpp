    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != c[0] && s[i] != c[c.size() - 1]) {
            result += s[i];
        }
    }
    return result;
}