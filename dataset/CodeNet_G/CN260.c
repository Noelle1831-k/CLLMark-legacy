#define MAX_N 16
typedef struct {
    int x, y;
} Point;
bool visible[MAX_N];
bool visited[MAX_N];
int n;
Point vertices[MAX_N];
int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool is_inside(Point a, Point b, Point c, Point p) {
    int cp1 = cross_product(a, b, p);
    int cp2 = cross_product(b, c, p);
    int cp3 = cross_product(c, a, p);
    if ((cp1 >= 0 && cp2 >= 0 && cp3 >= 0) || (cp1 <= 0 && cp2 <= 0 && cp3 <= 0))
        return true;
    return false;
}
void check_visibility(int index) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[index] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool visible = true;
            for (int j = 0; j < n; j++) {
                if (j != i && j != (i + 1) % n && j != (i - 1 + n) % n) {
                    if (is_inside(vertices[index], vertices[i], vertices[(i + 1) % n], vertices[j])) {
                        visible = false;
                        break;
                    }
                }
            }
            if (visible) {
                visited[i] = true;
                visited[(i + 1) % n] = true;
                visited[(i - 1 + n) % n] = true;
            }
        }
    }
}
int min_visible_vertices() {
    int min_visible = n;
    for (int i = 0; i < n; i++) {
        check_visibility(i);
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                count++;
            }
        }
        if (count < min_visible) {
            min_visible = count;
        }
    }
    return min_visible;
}