void calculateSumAndAverage() {
    int unitPrice, quantity;
    int totalAmount = 0;
    int totalQuantity = 0;
    int count = 0;
    double averageQuantity;
    while (scanf("%d,%d", &unitPrice, &quantity) != EOF) {
        totalAmount += unitPrice * quantity;
        totalQuantity += quantity;
        count++;
    }
    averageQuantity = (double)totalQuantity / count;
    averageQuantity = round(averageQuantity);
    printf("%d\n", totalAmount);
    printf("%d\n", (int)averageQuantity);
}