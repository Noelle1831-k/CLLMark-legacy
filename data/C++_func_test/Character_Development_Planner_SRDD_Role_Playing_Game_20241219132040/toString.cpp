string Character::toString() const {
    stringstream ss;
    ss << "Character Attributes:\n";
    for (const auto &attr : attributes) {
        ss << "- " << attr.first << ": " << attr.second << "\n";
    }
    ss << "Skills:\n";
    for (const auto &skill : skills) {
        ss << "- " << skill.getName() << " (Level: " << skill.getLevel() << ")\n";
    }
    return ss.str();
}