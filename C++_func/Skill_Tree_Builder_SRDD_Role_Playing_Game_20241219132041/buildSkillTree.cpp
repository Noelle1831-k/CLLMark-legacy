void UserInterface::buildSkillTree() {
    if (!skillTree) {
        cout << "No root skill exists. Create one first!" << endl;
        return;
    }
    string name, description;
    int maxLevel;
    cout << "Enter skill name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter skill description: ";
    getline(cin, description);
    cout << "Enter max skill level: ";
    cin >> maxLevel;
    Skill* newSkill = new Skill(name, description, maxLevel);
    skillTree->addSkill(newSkill, skillTree->getRootNode());
    cout << "Skill added to tree!" << endl;
}