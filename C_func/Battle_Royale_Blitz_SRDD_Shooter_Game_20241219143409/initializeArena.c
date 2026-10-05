void initializeArena(Arena *arena, int width, int height) {
    arena->width = width;
    arena->height = height;
    arena->shrinkRate = 1; 
    printf("Arena initialized with dimensions %dx%d.\n", arena->width, arena->height);
}