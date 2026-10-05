def is_tree_balanced(root):

    def check_balance(node):
        if node is None:
            return (0, True)
        left_height, left_balanced = check_balance(node.left)
        right_height, right_balanced = check_balance(node.right)
        current_balanced = left_balanced and right_balanced and (abs(left_height - right_height) <= 1)
        current_height = max(left_height, right_height) + 1
        return (current_height, current_balanced)
    _, is_balanced = check_balance(root)
    return is_balanced