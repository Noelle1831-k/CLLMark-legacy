void getRecommendations(Goal goals[MAX_GOALS], int goalCount) {
    for (int i = 0; i < goalCount; i++) {
        printf("For goal '%s' (Type: %d):\n", goals[i].name, goals[i].type);
        if (goals[i].type == FITNESS) {
            printf("  Try adding more workouts or tracking calories.\n");
        } else if (goals[i].type == CAREER) {
            printf("  Consider taking an online course or networking more.\n");
        } else if (goals[i].type == PERSONAL_DEVELOPMENT) {
            printf("  Try meditating or setting a daily reading habit.\n");
        }
        printf("--------------------\n");
    }
}