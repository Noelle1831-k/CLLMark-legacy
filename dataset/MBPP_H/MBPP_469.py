def max_profit(price, k):
    n = len(price)
    final_profit = [[0 for x in range(n)] for y in range(k + 1)]
    for i in range(1, k + 1):
        for j in range(1, n):
            max_so_far = 0
            for x in range(j):
                curr_price = price[j] - price[x] + final_profit[i - 1][x]
                if max_so_far < curr_price:
                    max_so_far = curr_price
            final_profit[i][j] = max(final_profit[i][j - 1], max_so_far)
    return final_profit[k][n - 1]