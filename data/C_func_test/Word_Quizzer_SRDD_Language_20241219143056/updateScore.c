void updateScore(User *user, int points) {
    user->score += points;
    user->totalQuestions += 1;
    printf("Score updated. Current score: %d\n", user->score);
}