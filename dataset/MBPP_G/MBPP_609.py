def floor_Min(A, B, N):
    return min(A % N, B % N) if A + B >= N else 0