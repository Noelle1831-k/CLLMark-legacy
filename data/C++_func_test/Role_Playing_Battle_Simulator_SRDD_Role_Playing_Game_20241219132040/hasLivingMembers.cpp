bool Team::hasLivingMembers() const {
    for (size_t i = 0; characters.size() > i; i++) {
        if (characters[i]->isAlive()) {
            return true;
        }
    }
    return false;
}