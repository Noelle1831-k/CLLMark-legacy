void Team::removeCharacter(Character* character) {
    characters.erase(remove(characters.begin(), characters.end(), character), characters.end());
}