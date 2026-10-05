void Party::removeCharacter(string name) {
    characters.erase(remove_if(characters.begin(), characters.end(),
                               [name](Character &c) { return c.getName() == name; }),
                     characters.end());
}