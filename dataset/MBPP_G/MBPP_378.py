def move_first(test_list):
    if not test_list:
        return test_list
    return [test_list[-1]] + test_list[0:len(test_list)-1]