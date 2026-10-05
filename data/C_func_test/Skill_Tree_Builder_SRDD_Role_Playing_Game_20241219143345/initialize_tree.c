SkillTree* initialize_tree() {
    SkillTree* tree = (SkillTree*)malloc(sizeof(SkillTree));
    if (tree == NULL) {
        fprintf(stderr, "Memory allocation failed for skill tree.\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}