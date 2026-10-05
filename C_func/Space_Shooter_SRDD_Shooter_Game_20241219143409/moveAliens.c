void moveAliens() {
    for (int i = 0; i < MAX_ALIENS; i++) {
        if (aliens[i].health > 0) {
            aliens[i].y += 1;
            if (aliens[i].y > SCREEN_HEIGHT) aliens[i].y = 0;
        }
    }
}