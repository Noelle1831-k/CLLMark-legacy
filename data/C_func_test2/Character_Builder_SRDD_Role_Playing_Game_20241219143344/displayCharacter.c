void displayCharacter(Character *character) {
    printf("Character Details:\n");
    printf("Race: %s\n", character->race->name);
    printf("Class: %s\n", character->class->name);
    printf("Level: %d\n", character->level);
    printf("Experience: %d\n", character->experience);
}