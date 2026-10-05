function countSamePair(nums1, nums2) {
  let sum = 0;
  for (let i = 0; i < nums1.length; i++) {
    sum += nums1[i] === nums2[i] ? 1 : 0;
  }
  return sum;
}
