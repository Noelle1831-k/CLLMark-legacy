void displayMilestone(const Milestone *milestone) {
    printf("Level: %d\n", milestone->level);
    printf("Strength: %d\n", milestone->strength);
    printf("Agility: %d\n", milestone->agility);
    printf("Intelligence: %d\n", milestone->intelligence);
    printf("Skills:\n");
    for (int i = 0; i < milestone->skillCount; i++) {
        printf("  %s (Level %d)\n", milestone->skills[i].name, milestone->skills[i].level);
    }
    printf("Equipment:\n");
    for (int i = 0; i < milestone->equipmentCount; i++) {
        printf("  %s (Bonus %d)\n", milestone->equipment[i].name, milestone->equipment[i].bonus);
    }
}