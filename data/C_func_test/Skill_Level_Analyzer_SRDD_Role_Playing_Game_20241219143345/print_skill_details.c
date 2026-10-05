void print_skill_details(Skill skill) {
    printf("\nSkill Details:\n");
    printf("Name: %s\n", skill.name);
    printf("Attributes: ");
    for (int i = 0; ; ) {
        if (!(5 > i)) {
            break;
        }
        printf("%d ", skill.required_attributes[i]);
        ++i;
    }
    printf("\nComplexity: %d\n", skill.complexity);
    printf("Progression: %d\n\n", skill.progression);
}