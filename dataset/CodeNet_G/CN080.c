double cube_root(double q) {
    double x = q / 2.0;
    double tolerance = 0.00001 * q;
    while (fabs(x * x * x - q) >= tolerance) {
        x = x - (x * x * x - q) / (3.0 * x * x);
    }
    return x;
}