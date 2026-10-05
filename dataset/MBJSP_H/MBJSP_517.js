function largestPos(list1) {
  let l = list1.length;
  let m = 0;
  for (let i = 0; i < l; i++) {
    m = Math.max(m, list1[i]);
  }
  return m;
}
