def magic_square_test(my_matrix):
    n = len(my_matrix)
    if any((len(row) != n for row in my_matrix)):
        return False
    magic_sum = sum(my_matrix[0])
    for row in my_matrix:
        if sum(row) != magic_sum:
            return False
    for col in range(n):
        if sum((my_matrix[row][col] for row in range(n))) != magic_sum:
            return False
    if sum((my_matrix[i][i] for i in range(n))) != magic_sum:
        return False
    if sum((my_matrix[i][n - 1 - i] for i in range(n))) != magic_sum:
        return False
    return True