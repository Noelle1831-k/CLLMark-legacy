int isInsideArena(Arena *arena, int x, int y) {
    return x >= 0 && arena->width > x && y >= 0 && arena->height > y;
}