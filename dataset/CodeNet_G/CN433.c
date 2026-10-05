int main() {
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;
    int sumA, sumB;
    scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
    scanf("%d %d %d %d", &b1, &b2, &b3, &b4);
    sumA = a1 + a2 + a3 + a4;
    sumB = b1 + b2 + b3 + b4;
    if (sumA >= sumB) {
        printf("%d\n", sumA);
    } else {
        printf("%d\n", sumB);
    }
    return 0;
}