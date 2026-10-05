void printDecimalPart(int p, int q) {
    int remainder = p % q;
    char result[81] = {0};
    char cycleMarker[81] = {0};
    int resultIndex = 0;
    int cycleStartIndex = -1;
    int remainderPositions[q];
    for (int i = 0; i < q; i++) {
        remainderPositions[i] = -1;
    }
    while (remainder != 0 && remainderPositions[remainder] == -1) {
        remainderPositions[remainder] = resultIndex;
        remainder *= 10;
        int digit = remainder / q;
        result[resultIndex++] = '0' + digit;
        remainder %= q;
    }
    result[resultIndex] = '\0';
    if (remainder != 0) {
        cycleStartIndex = remainderPositions[remainder];
        for (int i = cycleStartIndex; i < resultIndex; i++) {
            cycleMarker[i] = '^';
        }
    }
    if (cycleStartIndex == -1) {
        printf("%s\n", result);
    } else {
        printf("%s\n", result);
        for (int i = 0; i < cycleStartIndex; i++) {
            printf(" ");
        }
        printf("%s\n", cycleMarker + cycleStartIndex);
    }
}