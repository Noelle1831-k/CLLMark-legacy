int findLength(const char* str, int n) {
    int max_diff = 0;
    int current_diff = 0;
    for (int i = 0; i < n; i++) {
        current_diff += (str[i] == '0') ? 1 : -1;
        if (current_diff < 0) current_diff = 0;
        if (current_diff > max_diff) max_diff = current_diff;
    }
    return max_diff;
}