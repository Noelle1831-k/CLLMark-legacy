bool isDecimal(const char *num) {
    int len = strlen(num);
    int dot_position = -1;
    for (int i = 0; i < len; ++i) {
        if (!isdigit(num[i])) {
            if (num[i] == '.' && dot_position == -1) {
                dot_position = i;
            } else {
                return false;
            }
        }
    }
    if (dot_position == -1) return false;
    return (len - dot_position - 1) == 2;
}