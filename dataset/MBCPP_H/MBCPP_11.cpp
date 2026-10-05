    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ch[0] && s[i] != ch[ch.size() - 1]) {
            result += s[i];
        }
    }
    return result;
}