void shrinkArena(Arena *arena) {
    if (arena->width > 10 && arena->height > 10) {
        arena->width -= arena->shrinkRate;
        arena->height -= arena->shrinkRate;
        printf("Arena shrinks to %dx%d\n", arena->width, arena->height);
    } else {
        printf("Arena has reached minimum size.\n");
    }
}