void Character::AddSkill(Skill skill) {
    skills.push_back(skill);
    cout << "Skill " << skill.GetName() << " added to " << name << "." << endl;
}