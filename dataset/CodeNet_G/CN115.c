typedef struct {
    int x, y, z;
} Point;
int direction(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) * (c.z - a.z) +
           (b.y - a.y) * (c.z - a.z) * (c.x - a.x) +
           (b.z - a.z) * (c.x - a.x) * (c.y - a.y) -
           (c.x - a.x) * (b.y - a.y) * (a.z - b.z) -
           (c.y - a.y) * (b.z - a.z) * (a.x - b.x) -
           (c.z - a.z) * (b.x - a.x) * (a.y - b.y);
}
int is_inside(Point p, Point a, Point b, Point c) {
    int d1 = direction(p, a, b);
    int d2 = direction(p, b, c);
    int d3 = direction(p, c, a);
    return (d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0);
}
int main() {
    Point ship, enemy, v1, v2, v3;
    scanf("%d %d %d", &ship.x, &ship.y, &ship.z);
    scanf("%d %d %d", &enemy.x, &enemy.y, &enemy.z);
    scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
    scanf("%d %d %d", &v2.x, &v2.y, &v2.z);
    scanf("%d %d %d", &v3.x, &v3.y, &v3.z);
    if (is_inside(enemy, v1, v2, v3)) {
        printf("MISS\n");
        return 0;
    }
    if (is_inside(ship, v1, v2, v3)) {
        printf("MISS\n");
        return 0;
    }
    if (is_inside((Point){(ship.x + enemy.x) / 2, (ship.y + enemy.y) / 2, (ship.z + enemy.z) / 2}, v1, v2, v3)) {
        printf("MISS\n");
        return 0;
    }
    if (!is_inside(ship, v1, v2, v3) && is_inside((Point){enemy.x + 1, enemy.y, enemy.z}, v1, v2, v3) && 
        is_inside((Point){enemy.x - 1, enemy.y, enemy.z}, v1, v2, v3) &&
        is_inside((Point){enemy.x, enemy.y + 1, enemy.z}, v1, v2, v3) &&
        is_inside((Point){enemy.x, enemy.y - 1, enemy.z}, v1, v2, v3) &&
        is_inside((Point){enemy.x, enemy.y, enemy.z + 1}, v1, v2, v3) &&
        is_inside((Point){enemy.x, enemy.y, enemy.z - 1}, v1, v2, v3)) {
        printf("MISS\n");
        return 0;
    }
    printf("HIT\n");
    return 0;
}