void display_node(SkillTreeNode* node) {
    if (node == NULL) {
        printf("No node to display.\n");
        return;
    }
    display_skill(node->skill);
    for (int i = 0; i < node->child_count; i++) {
        display_node(node->children[i]);
    }
}