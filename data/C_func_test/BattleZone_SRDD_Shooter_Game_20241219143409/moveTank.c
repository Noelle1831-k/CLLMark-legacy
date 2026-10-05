void moveTank(Tank *tank) {
    int direction = rand() % 4;
    switch (direction) {
        case 0: if (tank->position.x < ARENA_WIDTH - 1) tank->position.x++; break;
        case 1: if (tank->position.x > 0) tank->position.x--; break;
        case 2: if (tank->position.y < ARENA_HEIGHT - 1) tank->position.y++; break;
        case 3: if (tank->position.y > 0) tank->position.y--; break;
    }
}