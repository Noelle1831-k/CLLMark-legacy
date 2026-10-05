void addSkill(Character *character, const char *skillName, int skillLevel) {
    if (character->skillCount < MAX_SKILLS) {
        strcpy(character->skills[character->skillCount].name, skillName);
        character->skills[character->skillCount].level = skillLevel;
        character->skillCount++;
    } else {
        printf("Skill limit reached.\n");
    }
}