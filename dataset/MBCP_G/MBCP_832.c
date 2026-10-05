int extractMax(const char *input) {
    int max = 0;
    int num = 0;
    while (*input) {
        if (isdigit(*input)) {
            num = num * 10 + (*input - '0');
        } else {
            if (num > max) {
                max = num;
            }
            num = 0;
        }
        input++;
    }
    if (num > max) {
        max = num;
    }
    return max;
}