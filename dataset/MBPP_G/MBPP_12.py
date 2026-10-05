def sort_matrix(M):
    return sorted(M, key=lambda row: sum(row))