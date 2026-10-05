double sign(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}
int is_point_in_triangle(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp) {
    double d1, d2, d3;
    int has_neg, has_pos;
    d1 = sign(xp, yp, x1, y1, x2, y2);
    d2 = sign(xp, yp, x2, y2, x3, y3);
    d3 = sign(xp, yp, x3, y3, x1, y1);
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}