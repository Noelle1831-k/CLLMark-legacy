def positive_count(nums):
    positive_numbers = [num for num in nums if num > 0]
    ratio = len(positive_numbers) / len(nums)
    return round(ratio, 2)