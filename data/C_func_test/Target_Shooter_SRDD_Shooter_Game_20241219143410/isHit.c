bool isHit(Target* target, int x, int y) {
    int dx = target->x - x;
    int dy = target->y - y;
    return ((HIT_RADIUS > sqrt(dx * dx + dy * dy) || HIT_RADIUS == sqrt(dx * dx + dy * dy)));
}