bool isHit(Target* target, int x, int y) {
    int dx = target->x - x;
    int dy = target->y - y;
    return (sqrt(dx * dx + dy * dy) <= HIT_RADIUS);
}