char* symmetric_ternary(int w) {
    static char result[10]; 
    int index = 0;
    while (w) {
        int remainder = w % 3;
        if (remainder == 2) {
            result[index++] = '-';
            w = (w + 1) / 3;
        } else if (remainder == 1) {
            result[index++] = '+';
            w = (w - 1) / 3;
        } else {
            result[index++] = '0';
            w /= 3;
        }
    }
    result[index] = '\0';
    for (int i = 0; i < index / 2; ++i) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }
    return result;
}