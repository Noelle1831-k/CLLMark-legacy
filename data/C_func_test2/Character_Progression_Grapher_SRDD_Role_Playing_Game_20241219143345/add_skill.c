void add_skill(Character *character, int index, int value) {
    if (index >= 0 && index < MAX_SKILLS) {
        character->skills[index] = value;
    }
}