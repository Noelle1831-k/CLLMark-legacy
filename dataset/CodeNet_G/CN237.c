#define MAX_TRIANGLES 100
typedef struct {
    double x, y;
} Point;
typedef struct {
    Point vertices[3];
    int illuminated;
} Triangle;
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int isPointNearLine(Point p, Point a, Point b, double tolerance) {
    double line_dist = fabs((b.y - a.y) * p.x - (b.x - a.x) * p.y + b.x * a.y - b.y * a.x) / distance(a, b);
    return line_dist <= tolerance;
}
int isSamePoint(Point p1, Point p2, double tolerance) {
    return distance(p1, p2) <= tolerance;
}
Point projectPoint(Point base, Point top, double length) {
    Point direction = {top.x - base.x, top.y - base.y};
    double scale = length / distance(base, top);
    Point projection = {base.x + direction.x * scale, base.y + direction.y * scale};
    return projection;
}
int canActivate(Triangle *t, Point start, Point end, double tolerance) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (isPointNearLine(start, t->vertices[i], t->vertices[j], tolerance) &&
                isPointNearLine(end, t->vertices[i], t->vertices[j], tolerance)) {
                return 1;
            }
        }
    }
    return 0;
}
int activateTriangles(Triangle triangles[], int n, Point start, Point end, double tolerance) {
    int activated = 0;
    for (int i = 0; i < n; i++) {
        if (!triangles[i].illuminated && canActivate(&triangles[i], start, end, tolerance)) {
            triangles[i].illuminated = 1;
            activated++;
        }
    }
    return activated;
}
int main() {
    int n;
    double d;
    Triangle triangles[MAX_TRIANGLES];
    while (scanf("%d %lf", &n, &d) == 2) {
        if (n == 0 && d == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lf %lf", &triangles[i].vertices[j].x, &triangles[i].vertices[j].y);
            }
            triangles[i].illuminated = 0;
        }
        int minTouches = 0;
        while (1) {
            int maxActivate = 0;
            Point bestStart, bestEnd;
            for (int i = 0; i < n; i++) {
                if (triangles[i].illuminated) continue;
                for (int j = 0; j < 3; j++) {
                    Point base = triangles[i].vertices[j];
                    for (int k = 0; k < 3; k++) {
                        if (k == j) continue;
                        Point top = triangles[i].vertices[k];
                        Point end = projectPoint(base, top, d);
                        int activated = activateTriangles(triangles, n, base, end, 0.01);
                        if (activated > maxActivate) {
                            maxActivate = activated;
                            bestStart = base;
                            bestEnd = end;
                        }
                    }
                }
            }
            if (maxActivate == 0) break;
            activateTriangles(triangles, n, bestStart, bestEnd, 0.01);
            minTouches++;
        }
        printf("%d\n", minTouches);
    }
    return 0;
}
