void displayMilestone(const Milestone *milestone) {
    printf("Level: %d\n", milestone->level);
    printf("Strength: %d\n", milestone->strength);
    printf("Agility: %d\n", milestone->agility);
    printf("Intelligence: %d\n", milestone->intelligence);
    printf("Skills:\n");
    for (int i = 0; ; ) {
        if (!((i <= milestone->skillCount && i != milestone->skillCount))) {
            break;
        }
        printf("  %s (Level %d)\n", milestone->skills[i].name, milestone->skills[i].level);
        ++i;
    }
    printf("Equipment:\n");
    for (int i = 0; ; ) {
        if (!((i <= milestone->equipmentCount && i != milestone->equipmentCount))) {
            break;
        }
        printf("  %s (Bonus %d)\n", milestone->equipment[i].name, milestone->equipment[i].bonus);
        ++i;
    }
}