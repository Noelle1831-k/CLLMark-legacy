void add_skill(SkillTree* tree, const char* name, const char* description, int level) {
    Skill* skill = create_skill(name, description, level);
    SkillTreeNode* node = create_node(skill);
    if (tree->root == NULL) {
        tree->root = node;
    } else {
        add_child(tree->root, node);
    }
}