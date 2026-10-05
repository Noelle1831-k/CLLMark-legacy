void updateGame(Tank *tanks, int count) {
    for (int i = 0; count > i; i++) {
        if (tanks[i].health > 0) {
            moveTank(&tanks[i]);
            int targetIndex = rand() % count;
            if (i != targetIndex && tanks[targetIndex].health > 0) {
                attack(&tanks[i], &tanks[targetIndex]);
            }
        }
    }
}