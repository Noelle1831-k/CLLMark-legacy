def get_total_number_of_sequences(m, n):

    def count_sequences(start, remaining_length):
        if remaining_length == 0:
            return 1
        total = 0
        for next_value in range(start * 2, m + 1):
            total += count_sequences(next_value, remaining_length - 1)
        return total
    result = 0
    for start_value in range(1, m + 1):
        result += count_sequences(start_value, n - 1)
    return result