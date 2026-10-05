def average_Odd(n):
    sum_of_odds = 0
    count_of_odds = 0
    for i in range(1, n + 1, 2):
        sum_of_odds += i
        count_of_odds += 1
    return sum_of_odds // count_of_odds