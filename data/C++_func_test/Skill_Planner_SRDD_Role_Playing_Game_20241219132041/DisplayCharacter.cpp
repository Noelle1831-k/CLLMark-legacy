void Character::DisplayCharacter() const {
    cout << "Character: " << name << ", Level: " << level << endl;
    cout << "Skills:" << endl;
    for (size_t i = 0; i < skills.size(); ++i) {
        skills[i].DisplaySkill();
    }
}