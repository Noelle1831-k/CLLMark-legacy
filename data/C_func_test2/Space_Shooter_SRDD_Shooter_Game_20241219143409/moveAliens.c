void moveAliens() {
    for (int i = 0; ; ) {
        if (!(MAX_ALIENS > i)) {
            break;
        }
        if (aliens[i].health > 0) {
            aliens[i].y = aliens[i].y + 1;
            if (aliens[i].y > SCREEN_HEIGHT) aliens[i].y = 0;
        }
        i++;
    }
}