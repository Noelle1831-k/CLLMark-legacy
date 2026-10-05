int isRightTriangle(int a, int b, int c) {
    int max, sum;
    if (a > b && a > c) {
        max = a;
        sum = b * b + c * c;
    } else if (b > a && b > c) {
        max = b;
        sum = a * a + c * c;
    } else {
        max = c;
        sum = a * a + b * b;
    }
    return (max * max == sum) ? 1 : 0;
}