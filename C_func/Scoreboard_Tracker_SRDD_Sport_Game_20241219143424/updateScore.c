void updateScore(int gameId, int score1, int score2) {
    for (int i = 0; i < scoreCount; i++) {
        if (scores[i].gameId == gameId) {
            scores[i].score1 = score1;
            scores[i].score2 = score2;
            printf("Score updated successfully.\n");
            return;
        }
    }
    if (scoreCount >= MAX_SCORES) {
        printf("Error: Maximum number of scores reached.\n");
        return;
    }
    scores[scoreCount].gameId = gameId;
    scores[scoreCount].score1 = score1;
    scores[scoreCount].score2 = score2;
    scoreCount++;
    printf("Score added successfully.\n");
}