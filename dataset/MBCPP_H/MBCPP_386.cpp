    int n = s.length();
    int maxCount = 0;
    int openBracket = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '[') {
            openBracket++;
        } else if (s[i] == ']') {
            openBracket--;
        }
        if (openBracket == -1) {
            maxCount++;
        }
    }
    return maxCount;
}