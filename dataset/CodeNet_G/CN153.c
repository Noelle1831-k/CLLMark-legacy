double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int point_in_triangle(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    int d1 = (x - x2) * (y1 - y2) - (x1 - x2) * (y - y2);
    int d2 = (x - x3) * (y2 - y3) - (x2 - x3) * (y - y3);
    int d3 = (x - x1) * (y3 - y1) - (x3 - x1) * (y - y1);
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}
int triangle_in_circle(int x1, int y1, int x2, int y2, int x3, int y3, int xc, int yc, int r) {
    return distance(x1, y1, xc, yc) <= r &&
           distance(x2, y2, xc, yc) <= r &&
           distance(x3, y3, xc, yc) <= r;
}
int circle_in_triangle(int xc, int yc, int r, int x1, int y1, int x2, int y2, int x3, int y3) {
    if (!point_in_triangle(xc, yc, x1, y1, x2, y2, x3, y3)) return 0;
    int x_proj, y_proj;
    double dist;
    x_proj = x1 + r * (x2 - x1) / distance(x1, y1, x2, y2);
    y_proj = y1 + r * (y2 - y1) / distance(x1, y1, x2, y2);
    dist = distance(x_proj, y_proj, xc, yc);
    if (dist > r) return 0;
    x_proj = x2 + r * (x3 - x2) / distance(x2, y2, x3, y3);
    y_proj = y2 + r * (y3 - y2) / distance(x2, y2, x3, y3);
    dist = distance(x_proj, y_proj, xc, yc);
    if (dist > r) return 0;
    x_proj = x3 + r * (x1 - x3) / distance(x3, y3, x1, y1);
    y_proj = y3 + r * (y1 - y3) / distance(x3, y3, x1, y1);
    dist = distance(x_proj, y_proj, xc, yc);
    if (dist > r) return 0;
    return 1;
}
int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int xc, int yc, int r) {
    if (point_in_triangle(xc, yc, x1, y1, x2, y2, x3, y3)) return 1;
    double dist1 = fabs((y2 - y1) * xc - (x2 - x1) * yc + x2 * y1 - y2 * x1) /
                   sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    if (dist1 <= r && (distance(x1, y1, xc, yc) <= r || distance(x2, y2, xc, yc) <= r)) return 1;
    double dist2 = fabs((y3 - y2) * xc - (x3 - x2) * yc + x3 * y2 - y3 * x2) /
                   sqrt((y3 - y2) * (y3 - y2) + (x3 - x2) * (x3 - x2));
    if (dist2 <= r && (distance(x2, y2, xc, yc) <= r || distance(x3, y3, xc, yc) <= r)) return 1;
    double dist3 = fabs((y1 - y3) * xc - (x1 - x3) * yc + x1 * y3 - y1 * x3) /
                   sqrt((y1 - y3) * (y1 - y3) + (x1 - x3) * (x1 - x3));
    if (dist3 <= r && (distance(x3, y3, xc, yc) <= r || distance(x1, y1, xc, yc) <= r)) return 1;
    return 0;
}
char determine_position(int x1, int y1, int x2, int y2, int x3, int y3, int xc, int yc, int r) {
    if (triangle_in_circle(x1, y1, x2, y2, x3, y3, xc, yc, r)) return 'b';
    if (
        circle_in_triangle(xc, yc, r, x1, y1, x2, y2, x3, y3)) return 'a';
    if (
        intersect(x1, y1, x2, y2, x3, y3, xc, yc, r)) return 'c';
    return 'd';
}