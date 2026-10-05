Character* createCharacter() {
    Character *character = (Character*)malloc(sizeof(Character));
    character->level = 1;
    character->experience = 0;
    return character;
}