def get_maxgold(gold, m, n):
    gold_table = [[0] * n for _ in range(m)]
    for col in range(n - 1, -1, -1):
        for row in range(m):
            right = gold_table[row][col + 1] if col != n - 1 else 0
            right_up = gold_table[row - 1][col + 1] if row != 0 and col != n - 1 else 0
            right_down = gold_table[row + 1][col + 1] if row != m - 1 and col != n - 1 else 0
            gold_table[row][col] = gold[row][col] + max(right, right_up, right_down)
    return max((gold_table[row][0] for row in range(m)))