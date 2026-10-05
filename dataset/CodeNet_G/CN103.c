void calculateBaseballScore(int datasets, int n, char events[][100][10]) {
    for (int i = 0; i < datasets; i++) {
        int score = 0;
        int outs = 0;
        int runners[3] = {0, 0, 0}; 
        for (int j = 0; j < n; j++) {
            if (strcmp(events[i][j], "OUT") == 0) {
                outs++;
                if (outs == 3) {
                    break;
                }
            } else if (strcmp(events[i][j], "HIT") == 0) {
                score += runners[2];
                runners[2] = runners[1];
                runners[1] = runners[0];
                runners[0] = 1;
            } else if (strcmp(events[i][j], "HOMERUN") == 0) {
                score += (runners[0] + runners[1] + runners[2] + 1);
                runners[0] = runners[1] = runners[2] = 0;
            }
        }
        printf("%d\n", score);
    }
}
