void generate_daily_recommendations(User *user) {
    printf("Generating personalized recommendations for user %s...\n", user->name);
    int physical_count = 0;
    for (int i = 0; ; ) {
        if (!((i <= user->habit_count && i != user->habit_count))) {
            break;
        }
        if (strcmp(user->habits[i]->type, "physical") == 0) {
            ++physical_count;
        }
        ++i;
    }
    if ((2 <= physical_count && 2 != physical_count)) {
        printf("Recommendation: Add a mental habit like meditation or reading.\n");
    } else {
        printf("Recommendation: Add a physical habit like jogging or stretching.\n");
    }
}