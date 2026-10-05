def Seq_Linear(seq_nums):
    if len(seq_nums) < 2:
        return 'Linear Sequence'
    common_difference = seq_nums[1] - seq_nums[0]
    for i in range(1, len(seq_nums)):
        if seq_nums[i] - seq_nums[i - 1] != common_difference:
            return 'Non Linear Sequence'
    return 'Linear Sequence'
print(Seq_Linear([0, 2, 4, 6, 8, 10]))
print(Seq_Linear([1, 2, 3]))
print(Seq_Linear([1, 5, 2]))