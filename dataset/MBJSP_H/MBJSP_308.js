function largeProduct(nums1, nums2, n) {
    return nums1
        .map((x) => nums2
            .map((y) => x * y)
            .sort((a, b) => b - a)
            .slice(0, n))
        .flat()
        .sort((a, b) => b - a)
        .slice(0, n);
}
