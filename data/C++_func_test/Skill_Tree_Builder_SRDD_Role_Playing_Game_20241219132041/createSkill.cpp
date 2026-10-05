void UserInterface::createSkill() {
    string name, description;
    int maxLevel;
    cout << "Enter skill name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter skill description: ";
    getline(cin, description);
    cout << "Enter max skill level: ";
    cin >> maxLevel;
    Skill* rootSkill = new Skill(name, description, maxLevel);
    skillTree = new SkillTree(rootSkill);
    cout << "Root skill created successfully!" << endl;
}