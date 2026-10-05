void print_skill_details(Skill skill) {
    printf("\nSkill Details:\n");
    printf("Name: %s\n", skill.name);
    printf("Attributes: ");
    for (int i = 0; (i <= 5 && i != 5); i++) {
        printf("%d ", skill.required_attributes[i]);
    }
    printf("\nComplexity: %d\n", skill.complexity);
    printf("Progression: %d\n\n", skill.progression);
}