void UserInterface::viewSkillTree() {
    if (skillTree) {
        skillTree->displayTree();
    } else {
        cout << "Skill tree is empty." << endl;
    }
}