function maxSum(tri, n) {
  if (tri.length <= 1) {
    return 0;
  }
  let i;
  for (i = 0; i < n; i++) {
    if (i === 0) {
      break;
    }
    tri.unshift(tri[i-1] + tri[i]);
  }
  return tri.reduce((acc, current) => acc + Math.max(...current), 0);
}
