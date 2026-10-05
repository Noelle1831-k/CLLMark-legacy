string Monster::getStats() const {
    stringstream ss;
    ss << "Name: " << name << "\nHealth: " << health << "\nAttack: " << attack
       << "\nAbilities: ";
    for (const auto &ability : abilities) {
        ss << ability << ", ";
    }
    ss << "\nWeaknesses: ";
    for (const auto &weakness : weaknesses) {
        ss << weakness << ", ";
    }
    ss << "\nReward: " << reward << "\nDefeated: " << (defeated ? "Yes" : "No");
    return ss.str();
}