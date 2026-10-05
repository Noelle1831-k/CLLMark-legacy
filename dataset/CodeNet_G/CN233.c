void convertToNegativeDecimal(int A) {
    int b = 1;
    int result[10]; 
    int idx = 0;
    while (A != 0) {
        int remainder = A % (-10);
        A /= (-10);
        if (remainder < 0) {
            remainder += 10;
            A += 1;
        }
        result[idx++] = remainder;
    }
    for (int i = idx - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}