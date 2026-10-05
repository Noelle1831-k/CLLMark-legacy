def is_Diff(n):
    even_sum = sum((int(d) for d in str(n) if int(d) % 2 == 0))
    odd_sum = sum((int(d) for d in str(n) if int(d) % 2 != 0))
    return even_sum == odd_sum