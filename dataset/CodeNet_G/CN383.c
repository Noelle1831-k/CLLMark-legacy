typedef struct {
    int x, y;
} Point;
int collinear(Point a, Point b, Point c) {
    return (b.y - a.y) * (c.x - b.x) == (b.x - a.x) * (c.y - b.y);
}
int check(int N, int K, Point* points) {
    if (K < 3) return 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int count = 2;
            for (int k = 0; k < N; k++) {
                if (k != i && k != j && collinear(points[i], points[j], points[k])) {
                    count++;
                    if (count >= K) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}