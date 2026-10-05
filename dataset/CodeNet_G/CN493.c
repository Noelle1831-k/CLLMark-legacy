int is_zigzag(const char* str) {
    int len = strlen(str);
    if (len == 1) return 1;
    int direction = 0; 
    for (int i = 1; i < len; i++) {
        if (str[i-1] < str[i]) {
            if (direction == -1) return 0;
            direction = 1;
        }
        else if (str[i-1] > str[i]) {
            if (direction == 1) return 0;
            direction = -1;
        }
        else return 0;
    }
    return 1;
}
int count_zigzag_numbers(const char* a, const char* b, int m) {
    char start[10501];
    char end[10501];
    strcpy(start, a);
    strcpy(end, b);
    int count = 0;
    int lenA = strlen(a);
    int lenB = strlen(b);
    int temp[10501];
    while (1) {
        if (is_zigzag(start)) count = (count + 1) % 10000;
        int carry = m;
        for (int i = lenA - 1; i >= 0; i--) {
            int digit_sum = (start[i] - '0') + carry;
            start[i] = (digit_sum % 10) + '0';
            carry = digit_sum / 10;
        }
        if ((carry > 0) || strcmp(start, end) > 0) break;
    }
    return count;
}