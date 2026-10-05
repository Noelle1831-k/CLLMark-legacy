function maxSumSubseq(a) {
  if (a == 0) return 0;

  var global = 0;
  var local = 0;
  var max = 0;
  for (i in a) {
    local = global + a[i];
    global = max;
    max = Math.max(local, max);
  }

  return max;
}
