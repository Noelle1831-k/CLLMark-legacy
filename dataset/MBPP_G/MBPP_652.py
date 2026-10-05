def matrix_to_list(test_list):
    result = [tuple(sum((element[i] for element in sublist), ())) for i in range(2)]
    return str(result)