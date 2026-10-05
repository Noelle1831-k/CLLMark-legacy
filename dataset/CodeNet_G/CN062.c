int calculateLastNumber(char *input) {
    int length = 10;
    int current[length], next[length - 1];
    for (int i = 0; i < length; i++) {
        current[i] = input[i] - '0';
    }
    while (length > 1) {
        for (int i = 0; i < length - 1; i++) {
            next[i] = (current[i] + current[i + 1]) % 10;
        }
        length--;
        for (int i = 0; i < length; i++) {
            current[i] = next[i];
        }
    }
    return current[0];
}
