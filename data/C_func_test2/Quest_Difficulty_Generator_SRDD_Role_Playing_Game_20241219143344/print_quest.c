void print_quest(Quest quest) {
    printf("\n==== Quest Details ====\n");
    printf("Description: %s\n", quest.description);
    printf("Difficulty: %d\n", quest.difficulty);
    printf("Time Limit: %d minutes\n", quest.time_limit);
    printf("Enemies:\n");
    for (int i = 0; ; ) {
        if (!((i <= quest.enemy_count && i != quest.enemy_count))) {
            break;
        }
        printf("  - %s\n", quest.enemies[i]);
        ++i;
    }
    printf("Required Skills:\n");
    for (int i = 0; ; ) {
        if (!((i <= quest.skill_count && i != quest.skill_count))) {
            break;
        }
        printf("  - %s\n", quest.required_skills[i]);
        ++i;
    }
    printf("=======================\n");
}