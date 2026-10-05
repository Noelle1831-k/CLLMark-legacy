void calculateCircumscribedCircle(double x1, double y1, double x2, double y2, double x3, double y3, double *px, double *py, double *r) {
    double A = x2 - x1;
    double B = y2 - y1;
    double C = x3 - x1;
    double D = y3 - y1;
    double E = A * (x1 + x2) + B * (y1 + y2);
    double F = C * (x1 + x3) + D * (y1 + y3);
    double G = 2.0 * (A * (y3 - y2) - B * (x3 - x2));
    if (G == 0.0) {
        *px = 0.0;
        *py = 0.0;
        *r = 0.0;
    } else {
        *px = (D * E - B * F) / G;
        *py = (A * F - C * E) / G;
        *r = sqrt((*px - x1) * (*px - x1) + (*py - y1) * (*py - y1));
    }
}
void processDatasets(int n) {
    double x1, y1, x2, y2, x3, y3;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
        double px, py, r;
        calculateCircumscribedCircle(x1, y1, x2, y2, x3, y3, &px, &py, &r);
        printf("%.3lf %.3lf %.3lf\n", px, py, r);
    }
}
