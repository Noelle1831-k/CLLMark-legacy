function kSmallestPairs(nums1, nums2, k) {
  var arr = [];
  for (var i = 0; i < nums1.length; i++) {
    for (var j = 0; j < nums2.length; j++) {
      arr.push([nums1[i], nums2[j]]);
    }
  }
  arr.sort(function(a, b) {
    return a[0] + a[1] - b[0] - b[1];
  });
  return arr.slice(0, k);
}
