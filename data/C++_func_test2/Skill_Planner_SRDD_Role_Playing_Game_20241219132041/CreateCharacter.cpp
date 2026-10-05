void SkillPlanner::CreateCharacter() {
    string name;
    int level;
    cout << "Enter character name: ";
    cin >> name;
    cout << "Enter character level: ";
    cin >> level;
    if (level < 1) {
        cout << "Invalid level. Level must be at least 1." << endl;
        return;
    }
    characters.emplace_back(name, level);
    cout << "Character " << name << " created." << endl;
}