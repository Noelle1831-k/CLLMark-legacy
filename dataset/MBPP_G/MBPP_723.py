def count_same_pair(nums1, nums2):
    return sum(map(lambda x: x[0] == x[1], zip(nums1, nums2)))