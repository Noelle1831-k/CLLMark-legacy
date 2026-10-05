typedef struct {
    double x, y;
} Point;
double cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int isPointInConvexHull(Point points[], int n, Point p) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (cross(points[i], points[(i+1)%n], p) < 0) {
            count++;
            if(count > 2) return 0;
        }
    }
    return 1;
}
void findConvexHull(Point points[], int n, int* hull, int* hullSize) {
    int i, t, k = 0;
    if (n <= 3) {
        for (i = 0; i < n; i++) hull[i] = i;
        *hullSize = n;
        return;
    }
    int l = 0;
    for (i = 1; i < n; i++) if (points[i].x < points[l].x) l = i;
    int p = l, q;
    do {
        hull[k++] = p;
        q = (p + 1) % n;
        for (i = 0; i < n; i++) 
            if (cross(points[p], points[i], points[q]) > 0) q = i;
        p = q;
    } while (p != l);
    *hullSize = k;
}
int main_hull(int n, Point points[]) {
    if (n == 0) return 0;
    int hull[100];
    int hullSize;
    findConvexHull(points, n, hull, &hullSize);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!isPointInConvexHull(points, hullSize, points[i]))
            count++;
    }
    return count;
}