void print_character(const Character* character) {
    printf("Character ID: %d\n", character->id);
    printf("Class: %s\n", (character->class == 0) ? "Warrior" : (character->class == 1) ? "Mage" : "Healer");
    printf("Health: %d, Attack: %d, Defense: %d, Ability Score: %d\n",
           character->health, character->attack, character->defense, character->ability_score);
}