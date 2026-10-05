function mulList(nums1, nums2) {
  let result = [];
  for (let i = 0; i < nums1.length; i++) {
    result.push(nums1[i] * nums2[i]);
  }
  return result;
}
