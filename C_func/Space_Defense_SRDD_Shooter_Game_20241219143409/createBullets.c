Bullet* createBullets() {
    Bullet* bullets = (Bullet*)malloc(sizeof(Bullet) * MAX_BULLETS);
    for (int i = 0; i < MAX_BULLETS; ++i) {
        bullets[i].isActive = false;
    }
    return bullets;
}