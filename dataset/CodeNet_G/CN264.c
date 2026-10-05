#define PI 3.14159265358979323846
typedef struct {
    int x, y;
} Coordinate;
typedef struct {
    int w, a;
} Wind;
int is_within_sector(int x, int y, int wx, int wy, int angle, int radius) {
    double rad = atan2(y, x) * (180 / PI);
    if (rad < 0) rad += 360;
    double dist = sqrt(x * x + y * y);
    if (dist > radius) return 0;
    double left = wx - (angle / 2.0);
    double right = wx + (angle / 2.0);
    if (right >= 360) {
        if (rad >= left || rad <= right - 360) return 1;
    } else if (left < 0) {
        if (rad >= left + 360 || rad <= right) return 1;
    } else {
        if (rad >= left && rad <= right) return 1;
    }
    return 0;
}
int is_unique_to_mine(Coordinate house, Wind wind, int du, int dm, int ds, Coordinate *ume, int U, Coordinate *momo, int M, Coordinate *sakura, int S, int radius) {
    int mine_only = 1;
    if (!is_within_sector(house.x, house.y, wind.w, wind.a, du, radius)) return 0;
    for (int i = 0; i < U; i++) {
        if (is_within_sector(house.x - ume[i].x, house.y - ume[i].y, wind.w, wind.a, du, radius)) {
            mine_only = 0;
            break;
        }
    }
    if (mine_only) {
        for (int i = 0; i < M; i++) {
            if (is_within_sector(house.x - momo[i].x, house.y - momo[i].y, wind.w, wind.a, dm, radius)) {
                mine_only = 0;
                break;
            }
        }
    }
    if (mine_only) {
        for (int i = 0; i < S; i++) {
            if (is_within_sector(house.x - sakura[i].x, house.y - sakura[i].y, wind.w, wind.a, ds, radius)) {
                mine_only = 0;
                break;
            }
        }
    }
    return mine_only;
}
