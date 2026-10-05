typedef struct {
    int wx;
    int wy;
    int r;
} Wall;
typedef struct {
    int tx;
    int ty;
    int sx;
    int sy;
} Position;
int doesIntersect(Wall wall, Position pos) {
    int dx = pos.sx - pos.tx;
    int dy = pos.sy - pos.ty;
    int fx = pos.tx - wall.wx;
    int fy = pos.ty - wall.wy;
    int a = dx * dx + dy * dy;
    int b = 2 * (fx * dx + fy * dy);
    int c = fx * fx + fy * fy - wall.r * wall.r;
    if (a == 0) {
        if (c <= 0) {
            return 1;
        } else {
            return 0;
        }
    }
    int discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return 0;
    }
    discriminant = (int) sqrt(discriminant);
    int t1 = (-b - discriminant) / (2 * a);
    int t2 = (-b + discriminant) / (2 * a);
    if ((t1 >= 0 && t1 <= a) || (t2 >= 0 && t2 <= a)) {
        return 1;
    }
    return 0;
}
void checkPositions(Wall walls[], int n, Position positions[], int m) {
    for (int i = 0; i < m; ++i) {
        int visible = 1;
        for (int j = 0; j < n; ++j) {
            if (doesIntersect(walls[j], positions[i])) {
                visible = 0;
                break;
            }
        }
        if (visible) {
            printf("Danger\n");
        } else {
            printf("Safe\n");
        }
    }
}