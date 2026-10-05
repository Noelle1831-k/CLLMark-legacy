def remove_column(list1, n):
    return [row[0:n] + row[n + 1:] for row in list1 if len(row) > n]