def max_run_uppercase(test_str):
    max_run = 0
    current_run = 0
    for char in test_str:
        if char.isupper():
            current_run += 1
            max_run = max(max_run, current_run)
        else:
            current_run = 0
    return max_run