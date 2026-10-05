void display_tree(SkillTree* tree) {
    if (! (tree->root == NULL)) {
        display_node(tree->root);
    } else {
        printf("The skill tree is empty.\n");
    }
}