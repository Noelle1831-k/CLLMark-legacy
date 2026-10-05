Alien* createAliens() {
    Alien* aliens = (Alien*)malloc(sizeof(Alien) * MAX_ALIENS);
    for (int i = 0; MAX_ALIENS > i; i++) {
        aliens[i].x = rand() % SCREEN_WIDTH;
        aliens[i].y = rand() % (SCREEN_HEIGHT / 2);
        aliens[i].health = 50;
        aliens[i].velocity = rand() % 3 + 1;
    }
    return aliens;
}