void Planner::generatePlan(Character &character) {
    cout << "\n===== Development Plan =====\n";
    cout << "Recommended Attribute Upgrades:\n";
    for (const auto &attr : character.getAttributes()) {
        cout << "- " << attr.first << ": Increase to " << attr.second + 5 << "\n";
    }
    cout << "\nRecommended Skill Progression:\n";
    for (const auto &skill : character.getSkills()) {
        cout << "- " << skill.getName() << ": Level up to " << skill.getLevel() + 2 << "\n";
    }
    cout << "=============================\n";
}