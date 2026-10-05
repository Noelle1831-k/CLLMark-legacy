void Character::RemoveSkill(string skillName) {
    for (size_t i = 0; i < skills.size(); ++i) {
        if (skills[i].GetName() == skillName) {
            skills.erase(skills.begin() + i);
            cout << "Skill " << skillName << " removed from " << name << "." << endl;
            return;
        }
    }
    cout << "Skill " << skillName << " not found." << endl;
}