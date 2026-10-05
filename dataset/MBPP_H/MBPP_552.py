def Seq_Linear(seq_nums):
    if len(seq_nums) < 2:
        return "Non Linear Sequence"
    seq_nums = [seq_nums[x] - seq_nums[x - 1] for x in range(1, len(seq_nums))]
    if len(set(seq_nums)) == 1:
        return "Linear Sequence"
    else:
        return "Non Linear Sequence"