void checkLevelUp(Character *character) {
    if (character->experience >= 100) {
        levelUp(character);
        character->experience -= 100;
    }
}