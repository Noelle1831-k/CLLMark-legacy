int find_max_level(const char *s) {
    int n = strlen(s);
    int j_count = 0, o_count = 0, i_count = 0;
    for (int idx = 0; idx < n; ++idx) {
        if (s[idx] == 'J') {
            j_count++;
        } else if (s[idx] == 'O') {
            if (o_count < j_count) {
                o_count++;
            }
        } else if (s[idx] == 'I') {
            if (i_count < o_count) {
                i_count++;
            }
        }
    }
    return i_count;
}