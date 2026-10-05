void find_treasure(int n) {
    double x = 0.0, y = 0.0;
    double angle = 0.0;
    for (int i = 1; i <= n; i++) {
        angle += M_PI / 2;
        x += cos(angle);
        y += sin(angle);
    }
    printf("%.2f %.2f\n", x, y);
}