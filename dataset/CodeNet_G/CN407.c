typedef struct {
    long long x, y;
} Point;
int isPointInShadow(Point *castle, int n, Point p) {
    long double ox = p.x, oy = p.y, oz = 0;
    long double sx = 0, sy = 0, sz = 1000000;
    for (int i = 0; i < n; i++) {
        Point p1 = castle[i];
        Point p2 = castle[(i + 1) % n];
        long double x1 = p1.x, y1 = p1.y, z1 = 100;
        long double x2 = p2.x, y2 = p2.y, z2 = 100;
        long double a1 = (y1 - sy) * (z2 - sz) - (y2 - sy) * (z1 - sz);
        long double b1 = (x2 - sx) * (z1 - sz) - (x1 - sx) * (z2 - sz);
        long double c1 = (x1 - sx) * (y2 - sy) - (x2 - sx) * (y1 - sy);
        long double a2 = (y1 - oy) * (z2 - oz) - (y2 - oy) * (z1 - oz);
        long double b2 = (x2 - ox) * (z1 - oz) - (x1 - ox) * (z2 - oz);
        long double c2 = (x1 - ox) * (y2 - oy) - (x2 - ox) * (y1 - oy);
        if ((a1 * ox + b1 * oy + c1 * oz) * (a1 * sx + b1 * sy + c1 * sz) < 0) continue;
        if ((a2 * sx + b2 * sy + c2 * sz) * (a2 * ox + b2 * oy + c2 * oz) < 0) continue;
        return 1;
    }
    return 0;
}
