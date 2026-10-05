def max_sum_rectangular_grid(grid, n):
    incl = max(grid[0][0], grid[1][0])
    excl = 0
    for i in range(n):
        excl_new = max(excl, incl)
        if i < n:
            incl = excl + max(grid[0][i], grid[1][i])
        excl = excl_new
    return max(excl, incl)