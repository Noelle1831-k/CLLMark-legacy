void check_circle_intersection(double xa, double ya, double ra, double xb, double yb, double rb) {
    double dx = xb - xa;
    double dy = yb - ya;
    double distance = sqrt(dx * dx + dy * dy);
    if (distance + rb < ra) {
        printf("2\n");
    } else if (distance + ra < rb) {
        printf("-2\n");
    } else if (distance == ra + rb || distance + ra == rb || distance + rb == ra) {
        printf("1\n");
    } else if (distance > ra + rb) {
        printf("0\n");
    } else {
        printf("1\n");
    }
}
