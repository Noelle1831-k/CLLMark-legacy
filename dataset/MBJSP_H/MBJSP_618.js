function divList(nums1, nums2) {
  if (nums1.length == nums2.length) {
    if (nums1[0] == nums2[0]) {
      for (let i = 0; i < nums1.length; i++) {
        nums1[i] /= nums2[i];
      }
    } else {
      for (let i = 0; i < nums1.length; i++) {
        nums1[i] /= nums2[i];
      }
    }
  } else {
    for (let i = 0; i < nums1.length; i++) {
      nums1[i] = (nums1[i] / nums2[i]) % nums2[i];
    }
  }
  return nums1;
}
