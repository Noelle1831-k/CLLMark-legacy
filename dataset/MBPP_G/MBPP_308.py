def large_product(nums1, nums2, N):
    from heapq import nlargest
    products = [x * y for x in nums1 for y in nums2]
    return nlargest(N, products)