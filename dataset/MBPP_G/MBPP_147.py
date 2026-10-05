def max_path_sum(tri, m, n):
    for i in range(m - 1, -1, -1):
        for j in range(i + 1):
            tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1])
    return tri[0][0]