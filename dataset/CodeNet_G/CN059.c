int main() {
    double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xa1, &ya1, &xa2, &ya2, &xb1, &yb1, &xb2, &yb2) == 8) {
        if (xa1 > xa2) { double temp = xa1; xa1 = xa2; xa2 = temp; }
        if (ya1 > ya2) { double temp = ya1; ya1 = ya2; ya2 = temp; }
        if (xb1 > xb2) { double temp = xb1; xb1 = xb2; xb2 = temp; }
        if (yb1 > yb2) { double temp = yb1; yb1 = yb2; yb2 = temp; }
        if (xa2 < xb1 || xa1 > xb2 || ya2 < yb1 || ya1 > yb2)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
