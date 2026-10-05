def find_combinations(test_list):
    result = []
    for i in range(len(test_list)):
        for j in range(i + 1, len(test_list)):
            sum1 = test_list[i][0] + test_list[j][0]
            sum2 = test_list[i][1] + test_list[j][1]
            result.append((sum1, sum2))
    return result