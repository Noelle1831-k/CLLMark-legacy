SkillTreeNode* create_node(Skill* skill) {
    SkillTreeNode* node = (SkillTreeNode*)malloc(sizeof(SkillTreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed for skill tree node.\n");
        exit(EXIT_FAILURE);
    }
    node->skill = skill;
    node->child_count = 0;
    return node;
}