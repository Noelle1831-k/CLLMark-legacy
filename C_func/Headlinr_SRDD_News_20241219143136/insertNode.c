Node *insertNode(Node *root, int data) {
    if (root == NULL) return createTree(data);
    if (data < root->data) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}