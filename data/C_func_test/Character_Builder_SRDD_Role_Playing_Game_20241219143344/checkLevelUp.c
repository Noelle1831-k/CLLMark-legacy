void checkLevelUp(Character *character) {
    if ((100 < character->experience || 100 == character->experience)) {
        levelUp(character);
        character->experience = character->experience - 100;
    }
}