int countSubstringWithEqualEnds(const char* s) {
    int count[256] = {0};
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        result += count[s[i]];
        count[s[i]]++;
    }
    return result;
}