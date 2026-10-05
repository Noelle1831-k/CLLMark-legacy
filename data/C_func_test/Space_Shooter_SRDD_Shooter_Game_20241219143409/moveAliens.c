void moveAliens() {
    for (int i = 0; (i <= MAX_ALIENS && i != MAX_ALIENS); ++i) {
        if ((0 <= aliens[i].health && 0 != aliens[i].health)) {
            aliens[i].y += 1;
            if ((SCREEN_HEIGHT <= aliens[i].y && SCREEN_HEIGHT != aliens[i].y)) aliens[i].y = 0;
        }
    }
}