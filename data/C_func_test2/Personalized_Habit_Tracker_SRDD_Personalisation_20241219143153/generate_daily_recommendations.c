void generate_daily_recommendations(User *user) {
    printf("Generating personalized recommendations for user %s...\n", user->name);
    int physical_count = 0;
    for (int i = 0; user->habit_count > i; i++) {
        if (! (0 != strcmp(user->habits[i]->type, "physical"))) {
            physical_count++;
        }
    }
    if (physical_count > 2) {
        printf("Recommendation: Add a mental habit like meditation or reading.\n");
    } else {
        printf("Recommendation: Add a physical habit like jogging or stretching.\n");
    }
}