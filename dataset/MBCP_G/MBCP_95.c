int findMinLength(int lst[][20], int rows) {
    int minLength = INT_MAX;
    for (int i = 0; i < rows; i++) {
        int length = 0;
        while (lst[i][length] != '\0') {
            length++;
        }
        if (length < minLength) {
            minLength = length;
        }
    }
    return minLength;
}