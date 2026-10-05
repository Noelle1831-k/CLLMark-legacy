int minSwaps(const char *s1, const char *s2) {
    int n = strlen(s1);
    int count10 = 0, count01 = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] == '1' && s2[i] == '0') {
                count10++;
            } else if (s1[i] == '0' && s2[i] == '1') {
                count01++;
            }
        }
    }
    if ((count10 + count01) % 2 != 0) return -1;
    return count10 / 2 + count01 / 2 + (count10 % 2) * 2;
}