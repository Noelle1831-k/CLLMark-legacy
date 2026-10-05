def sum_digits_twoparts(N):

    def digit_sum(x):
        return sum((int(d) for d in str(x)))
    max_sum = 0
    for i in range(1, N):
        part1, part2 = (i, N - i)
        current_sum = digit_sum(part1) + digit_sum(part2)
        max_sum = max(max_sum, current_sum)
    return max_sum