void renderArena(Tank *tanks, int count) {
    printf("Rendering arena...\n");
    for (int i = 0; i < count; i++) {
        printf("Tank %d at (%d, %d) with health %d\n", tanks[i].id, tanks[i].position.x, tanks[i].position.y, tanks[i].health);
    }
}