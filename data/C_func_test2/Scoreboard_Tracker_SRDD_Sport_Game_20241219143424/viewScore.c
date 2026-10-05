void viewScore(int gameId) {
    for (int i = 0; i < scoreCount; i++) {
        if (scores[i].gameId == gameId) {
            printf("Game ID: %d, Score: %d - %d\n", gameId, scores[i].score1, scores[i].score2);
            return;
        }
    }
    printf("No score found for game ID %d.\n", gameId);
}