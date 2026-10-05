typedef struct {
    int x, y;
} Point;
int calculateArea(Point p1, Point p2, Point p3, Point p4) {
    int dx1 = p2.x - p1.x;
    int dy1 = p2.y - p1.y;
    int dx2 = p3.x - p1.x;
    int dy2 = p3.y - p1.y;
    if (dx1 * dx2 + dy1 * dy2 != 0)
        return 0;
    int side1Squared = dx1 * dx1 + dy1 * dy1;
    int side2Squared = dx2 * dx2 + dy2 * dy2;
    if (side1Squared != side2Squared)
        return 0;
    return side1Squared;
}
int compare(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    if (p1->x != p2->x)
        return p1->x - p2->x;
    return p1->y - p2->y;
}
int maxSquareArea(Point points[], int n) {
    int maxArea = 0;
    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            for (int k = j + 1; k < n - 1; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    int area = calculateArea(points[i], points[j], points[k], points[l]);
                    if (area > maxArea)
                        maxArea = area;
                }
            }
        }
    }
    return maxArea;
}