typedef struct {
    double x;
    double y;
} Point;
typedef struct {
    Point points[7];
} Polygon;
Polygon* calculatePolygons(int startx, int starty, int endx, int endy, int radius, int* count) {
    const double sqrt3 = sqrt(3);
    const int dx[] = {-1, 0, 1, 1, 0, -1};
    const double dy[] = {-sqrt3 / 2, sqrt3 / 2, sqrt3 / 2, -sqrt3 / 2, -sqrt3 / 2 * 3, -sqrt3 / 2 * 3};
    int numPolygons = (endx - startx + 1) * (endy - starty + 1);
    *count = numPolygons;
    Polygon* polygons = (Polygon*)malloc(numPolygons * sizeof(Polygon));
    int index = 0;
    for (int x = startx; x <= endx; ++x) {
        for (int y = starty; y <= endy; ++y) {
            double centerX = (double)x * 3 * radius / 2.0;
            double centerY = (double)y * sqrt3 * radius;
            if (y % 2 != 0) {
                centerX += 1.5 * radius;
            }
            for (int i = 0; i < 6; ++i) {
                polygons[index].points[i].x = centerX + dx[i] * radius;
                polygons[index].points[i].y = centerY + dy[i] * radius;
            }
            polygons[index].points[6] = polygons[index].points[0];
            ++index;
        }
    }
    return polygons;
}