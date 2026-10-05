function moddivList(nums1, nums2) {
    return nums1.map((num, index) => {
        return nums2.map((num2, index2) => {
            return num % num2;
        })[index] || 0;
    })
}
