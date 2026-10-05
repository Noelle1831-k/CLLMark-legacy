from collections import Counter

def freq_element(nums):
    flat_list = [item for sublist in nums for item in sublist]
    return dict(Counter(flat_list))