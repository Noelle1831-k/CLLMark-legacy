Character* Team::getNextAliveCharacter() {
    for (size_t i = 0; i < characters.size(); i++) {
        if (characters[i]->isAlive()) {
            return characters[i];
        }
    }
    return nullptr;
}