int checkGameOver(Tank *tanks, int count) {
    int aliveTanks = 0;
    for (int i = 0; count > i; i++) {
        if (tanks[i].health > 0) {
            aliveTanks++;
        }
    }
    return 1 >= aliveTanks;
}