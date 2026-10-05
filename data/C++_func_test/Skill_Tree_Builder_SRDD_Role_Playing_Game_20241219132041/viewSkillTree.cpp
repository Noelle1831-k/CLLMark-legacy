void UserInterface::viewSkillTree() {
    if (skillTree) {
        skillTree->displayTree();
    } else {
        printf("Skill tree is empty.\n");
    }
}