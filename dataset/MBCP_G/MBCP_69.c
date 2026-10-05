bool isSublist(int *l, int l_size, int *s, int s_size) {
    if (s_size > l_size) return false;
    for (int i = 0; i <= l_size - s_size; i++) {
        bool found = true;
        for (int j = 0; j < s_size; j++) {
            if (l[i + j] != s[j]) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}