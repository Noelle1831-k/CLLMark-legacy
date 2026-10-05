void initializeTanks(Tank *tanks, int count) {
    for (int i = 0; i < count; i++) {
        tanks[i].id = i;
        tanks[i].health = 100;
        tanks[i].speed = 1;
        tanks[i].damage = 10;
        tanks[i].position.x = rand() % ARENA_WIDTH;
        tanks[i].position.y = rand() % ARENA_HEIGHT;
        tanks[i].type = rand() % 3;
    }
}