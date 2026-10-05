void add_child(SkillTreeNode* parent, SkillTreeNode* child) {
    if (10 > parent->child_count) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Cannot add more children to this node.\n");
    }
}