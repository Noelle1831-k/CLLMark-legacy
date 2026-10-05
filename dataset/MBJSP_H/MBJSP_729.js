function addList(nums1, nums2) {
    return nums1.map(n => n + nums2.shift());
}
