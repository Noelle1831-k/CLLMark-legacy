void updateGame(Tank *tanks, int count) {
    for (int i = 0; i < count; i++) {
        if (tanks[i].health > 0) {
            moveTank(&tanks[i]);
            int targetIndex = rand() % count;
            if (targetIndex != i && tanks[targetIndex].health > 0) {
                attack(&tanks[i], &tanks[targetIndex]);
            }
        }
    }
}