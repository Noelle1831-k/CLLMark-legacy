void SkillPlanner::DisplayPlanner() const {
    for (size_t i = 0; i < characters.size(); ++i) {
        characters[i].DisplayCharacter();
    }
}