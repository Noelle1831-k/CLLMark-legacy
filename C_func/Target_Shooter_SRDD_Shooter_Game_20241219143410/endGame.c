void endGame() {
    printf("\nGame Over! Final Score: %d\n", getScore(&player));
    updateLeaderboard(getScore(&player));
    displayLeaderboard();
}