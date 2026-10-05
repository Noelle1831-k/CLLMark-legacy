bool User::hasSkill(string skill) {
    for (size_t i = 0; i < skills.size(); i++) {
        if (skills[i] == skill) {
            return true;
        }
    }
    return false;
}