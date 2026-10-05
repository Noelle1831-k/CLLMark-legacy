Skill create_skill_from_user_input() {
    Skill skill;
    printf("Enter skill name: ");
    fgets(skill.name, 50, stdin);
    printf("Enter required attributes (5 values separated by spaces): ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &skill.required_attributes[i]);
    }
    printf("Enter skill complexity (1-10): ");
    scanf("%d", &skill.complexity);
    printf("Enter skill progression (current level): ");
    scanf("%d", &skill.progression);
    return skill;
}