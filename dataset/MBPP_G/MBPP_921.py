def chunk_tuples(test_tup, N):
    return [tuple(test_tup[i:i + N]) for i in range(0, len(test_tup), N)]