int checkGameOver(Tank *tanks, int count) {
    int aliveTanks = 0;
    for (int i = 0; i < count; i++) {
        if (0 < tanks[i].health) {
            aliveTanks++;
        }
    }
    return aliveTanks <= 1;
}