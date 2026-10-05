double cross_product(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}
int is_convex(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd) {
    double cross1 = cross_product(xb - xa, yb - ya, xc - xb, yc - yb);
    double cross2 = cross_product(xc - xb, yc - yb, xd - xc, yd - yc);
    double cross3 = cross_product(xd - xc, yd - yc, xa - xd, ya - yd);
    double cross4 = cross_product(xa - xd, ya - yd, xb - xa, yb - ya);
    int sign1 = (cross1 > 0) - (cross1 < 0);
    int sign2 = (cross2 > 0) - (cross2 < 0);
    int sign3 = (cross3 > 0) - (cross3 < 0);
    int sign4 = (cross4 > 0) - (cross4 < 0);
    return (sign1 == sign2) && (sign2 == sign3) && (sign3 == sign4) ? 1 : 0;
}