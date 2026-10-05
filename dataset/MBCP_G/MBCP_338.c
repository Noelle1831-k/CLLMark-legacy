int countSubstringWithEqualEnds(char* s) {
    int cnt[256] = {0};
    int result = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        cnt[(int)s[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (cnt[i] > 0) {
            result += (cnt[i] * (cnt[i] + 1)) / 2;
        }
    }
    return result;
}