void display_skill(Skill* skill) {
    if (skill == NULL) {
        printf("No skill to display.\n");
        return;
    }
    printf("Skill Name: %s\n", skill->name);
    printf("Description: %s\n", skill->description);
    printf("Level: %d\n", skill->level);
}