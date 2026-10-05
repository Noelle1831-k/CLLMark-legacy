typedef struct {
    double x, y;
} Point;
double polygonArea(Point vertices[], int n) {
    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[i].y * vertices[j].x;
    }
    return fabs(area) / 2.0;
}
