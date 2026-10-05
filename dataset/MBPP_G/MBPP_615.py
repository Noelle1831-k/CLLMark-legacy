def average_tuple(nums):
    return [sum(x) / len(x) for x in zip(*nums)]