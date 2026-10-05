double dot_product(double ax, double ay, double bx, double by) {
    return ax * bx + ay * by;
}
int main() {
    double x_a, y_a, x_b, y_b, x_c, y_c, x_d, y_d;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", 
                 &x_a, &y_a, &x_b, &y_b, &x_c, &y_c, &x_d, &y_d) == 8) {
        double ab_x = x_b - x_a;
        double ab_y = y_b - y_a;
        double cd_x = x_d - x_c;
        double cd_y = y_d - y_c;
        if (dot_product(ab_x, ab_y, cd_x, cd_y) == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}