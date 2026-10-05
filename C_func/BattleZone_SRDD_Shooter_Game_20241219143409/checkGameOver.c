int checkGameOver(Tank *tanks, int count) {
    int aliveTanks = 0;
    for (int i = 0; i < count; i++) {
        if (tanks[i].health > 0) {
            aliveTanks++;
        }
    }
    return aliveTanks <= 1;
}