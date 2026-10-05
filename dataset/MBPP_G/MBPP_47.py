def compute_Last_Digit(A, B):
    if A > B:
        return 0
    elif A == B:
        return 1
    else:
        result = 1
        for i in range(A + 1, B + 1):
            result *= i
        return result % 10