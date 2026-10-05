void addSkills(Character *character) {
    if ((MAX_SKILLS < character->skillCount || MAX_SKILLS == character->skillCount)) {
        printf("Skill limit reached. Cannot add more skills.\n");
        return;
    }
    printf("Enter skill name to add: ");
    scanf("%s", character->skills[character->skillCount]);
    character->skillCount++;
    printf("Skill added successfully!\n");
}