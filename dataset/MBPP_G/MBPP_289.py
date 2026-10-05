def odd_Days(N):
    return (N * 365 + N // 4 - N // 100 + N // 400) % 7