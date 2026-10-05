void Character::addSkill(string skillName, int level) {
    skills.push_back(Skill(skillName, level));
}