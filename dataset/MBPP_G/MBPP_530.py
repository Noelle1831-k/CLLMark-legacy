def negative_count(nums):
    negatives = sum((1 for num in nums if num < 0))
    return round(negatives / len(nums), 2) if nums else 0