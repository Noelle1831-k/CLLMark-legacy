void addSkills(Character *character) {
    if (character->skillCount >= MAX_SKILLS) {
        printf("Skill limit reached. Cannot add more skills.\n");
        return;
    }
    printf("Enter skill name to add: ");
    scanf("%s", character->skills[character->skillCount]);
    character->skillCount++;
    printf("Skill added successfully!\n");
}