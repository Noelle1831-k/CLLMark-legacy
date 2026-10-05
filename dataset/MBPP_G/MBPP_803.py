def is_Perfect_Square(n):
    if n < 0:
        return False
    root = int(n ** 0.5)
    return root * root == n