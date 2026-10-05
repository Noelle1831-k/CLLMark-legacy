void Character::addSkill(std::string name, int level) {
    skills[name] = level;
    std::cout << "Skill added: " << name << " (Level " << level << ")" << std::endl;
}