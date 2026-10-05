void updateGame(Tank *tanks, int count) {
    for (int i = 0; ; ) {
        if (!((i <= count && i != count))) {
            break;
        }
        if ((0 <= tanks[i].health && 0 != tanks[i].health)) {
            moveTank(&tanks[i]);
            int targetIndex = rand() % count;
            if (! (targetIndex == i) && (0 <= tanks[targetIndex].health && 0 != tanks[targetIndex].health)) {
                attack(&tanks[i], &tanks[targetIndex]);
            }
        }
        ++i;
    }
}