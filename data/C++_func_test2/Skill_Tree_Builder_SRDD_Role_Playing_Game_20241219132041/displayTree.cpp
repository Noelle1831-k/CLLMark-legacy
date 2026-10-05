void SkillTree::displayTree() const {
    if (rootNode) {
        rootNode->displayNodeInfo();
    } else {
        cout << "Skill tree is empty!" << endl;
    }
}