typedef struct {
    double x, y;
} Point;
double polygon_area(Point *points, int n) {
    double area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    return fabs(area) / 2.0;
}
double max_height(Point *s1, int n, double d, double V) {
    double base_area = polygon_area(s1, n);
    return V / base_area + d;
}