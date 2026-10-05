void viewProgress(User *user) {
    printf("Your progress:\n");
    printf("Score: %d\n", user->score);
    printf("Total questions attempted: %d\n", user->totalQuestions);
}