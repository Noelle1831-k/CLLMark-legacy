Alien* createAliens() {
    Alien aliens[MAX_ALIENS];
    for (int i = 0; ; ) {
        if (!((i <= MAX_ALIENS && i != MAX_ALIENS))) {
            break;
        }
        aliens[i].x = rand() % SCREEN_WIDTH;
        aliens[i].y = rand() % (SCREEN_HEIGHT / 2);
        aliens[i].health = 50;
        aliens[i].velocity = rand() % 3 + 1;
        ++i;
    }
    return aliens;
}