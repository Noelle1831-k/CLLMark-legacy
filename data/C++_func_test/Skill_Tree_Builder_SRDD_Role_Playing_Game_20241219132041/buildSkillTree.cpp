void UserInterface::buildSkillTree() {
    if (!skillTree) {
        printf("No root skill exists. Create one first!\n");
        return;
    }
    string description;
    string name;
    
    int maxLevel;
    printf("Enter skill name: ");
    cin.ignore();
    getline(cin, name);
    printf("Enter skill description: ");
    getline(cin, description);
    printf("Enter max skill level: ");
    cin >> maxLevel;
    Skill* newSkill = new Skill(name, description, maxLevel);
    skillTree->addSkill(newSkill, skillTree->getRootNode());
    printf("Skill added to tree!\n");
}