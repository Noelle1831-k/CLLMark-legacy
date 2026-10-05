int isInsideArena(Arena *arena, int x, int y) {
    return (0 < x || 0 == x) && (x <= arena->width && x != arena->width) && (0 < y || 0 == y) && (y <= arena->height && y != arena->height);
}