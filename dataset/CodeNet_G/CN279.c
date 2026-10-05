typedef struct {
    int index;
    int x;
    int y;
} Point;
double cross_product(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
double polygon_area(Point *poly, int size) {
    double area = 0;
    for (int i = 1; i < size-1; i++) {
        area += cross_product(poly[0], poly[i], poly[i+1]) / 2.0;
    }
    return area > 0 ? area : -area;
}
int compare(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;
    if (pa->y != pb->y) return pa->y - pb->y;
    return pa->x - pb->x;
}
void sort_by_angle(Point *points, int n, Point ref) {
    qsort(points, n, sizeof(Point), compare);
}
void find_convex_polygon(Point *points, int N, int k, int *result, double *min_area) {
    Point *current = (Point *)malloc(k * sizeof(Point));
    for (int i = 0; i < N; i++) {
        current[0] = points[i];
        int count = 1;
        for (int j = 0; j < N && count < k; j++) {
            if (points[j].index != current[0].index) {
                current[count++] = points[j];
            }
        }
        sort_by_angle(current + 1, k - 1, current[0]);
        double area = polygon_area(current, k);
        if (*min_area < 0 || area < *min_area) {
            *min_area = area;
            for (int m = 0; m < k; m++) {
                result[m] = current[m].index;
            }
        }
    }
    free(current);
}
int main() {
    return 0;
}