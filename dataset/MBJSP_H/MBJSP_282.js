function subList(nums1, nums2) {
  return nums1.map((number) => {
    return number - nums2[nums1.indexOf(number)];
  });
}
