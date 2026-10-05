void Visualizer::showCharacter(Character &character) {
    cout << "\n===== Character Visualization =====\n";
    cout << "Attributes:\n";
    for (const auto &attr : character.getAttributes()) {
        cout << attr.first << ": ";
        for (int i = 0; i < attr.second; ++i) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "Skills:\n";
    for (const auto &skill : character.getSkills()) {
        cout << skill.getName() << ": ";
        for (int i = 0; i < skill.getLevel(); ++i) {
            cout << "+";
        }
        cout << "\n";
    }
    cout << "===================================\n";
}