void updateLeaderboard(int score) {
    for (int i = 0; i < MAX_SCORES; i++) {
        if (score > highScores[i]) {
            for (int j = MAX_SCORES - 1; j > i; j--) {
                highScores[j] = highScores[j - 1];
            }
            highScores[i] = score;
            break;
        }
    }
}