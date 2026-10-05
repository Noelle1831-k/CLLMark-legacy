int getMaxScore(int n, int c, int lighting[30][16], int tapping[30][16]) {
    int maxScore = 0;
    int currentLights[16] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 16; ++j) {
            currentLights[j] |= lighting[i][j];
        }
        int bestScoreForThisBeat = 0;
        for (int j = 0; j < c; ++j) {
            int score = 0;
            for (int k = 0; k < 16; ++k) {
                score += currentLights[k] && tapping[j][k];
            }
            if (score > bestScoreForThisBeat) {
                bestScoreForThisBeat = score;
            }
        }
        maxScore += bestScoreForThisBeat;
        for (int k = 0; k < 16; ++k) {
            if (currentLights[k]) {
                for (int j = 0; j < c; ++j) {
                    if (tapping[j][k]) {
                        currentLights[k] = 0;
                        break;
                    }
                }
            }
        }
    }
    return maxScore;
}