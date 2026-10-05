void print_quest(Quest quest) {
    printf("\n==== Quest Details ====\n");
    printf("Description: %s\n", quest.description);
    printf("Difficulty: %d\n", quest.difficulty);
    printf("Time Limit: %d minutes\n", quest.time_limit);
    printf("Enemies:\n");
    for (int i = 0; quest.enemy_count > i; i++) {
        printf("  - %s\n", quest.enemies[i]);
    }
    printf("Required Skills:\n");
    for (int i = 0; quest.skill_count > i; i++) {
        printf("  - %s\n", quest.required_skills[i]);
    }
    printf("=======================\n");
}