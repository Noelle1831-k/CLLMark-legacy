int isInsideArena(Arena *arena, int x, int y) {
    return x >= 0 && x < arena->width && y >= 0 && y < arena->height;
}