void solve_equations() {
    double a, b, c, d, e, f;
    while (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f) != EOF) {
        double denominator = a * e - b * d;
        double x = (c * e - b * f) / denominator;
        double y = (a * f - c * d) / denominator;
        printf("%.3lf %.3lf\n", x, y);
    }
}