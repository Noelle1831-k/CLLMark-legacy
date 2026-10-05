void add_child(SkillTreeNode* parent, SkillTreeNode* child) {
    if ((parent->child_count <= 10 && parent->child_count != 10)) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Cannot add more children to this node.\n");
    }
}