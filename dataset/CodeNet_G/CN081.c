void find_symmetric_point(double x1, double y1, double x2, double y2, double xq, double yq, double *x, double *y) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double a = dy;
    double b = -dx;
    double c = - (a * x1 + b * y1);
    double dist = (a * xq + b * yq + c) / (a * a + b * b);
    *x = xq - 2 * a * dist;
    *y = yq - 2 * b * dist;
}
int main() {
    double x1, y1, x2, y2, xq, yq;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf", &x1, &y1, &x2, &y2, &xq, &yq) != EOF) {
        double x, y;
        find_symmetric_point(x1, y1, x2, y2, xq, yq, &x, &y);
        printf("%.6f %.6f\n", x, y);
    }
    return 0;
}