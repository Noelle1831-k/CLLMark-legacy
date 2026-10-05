function extractIndexList(l1, l2, l3) {
  let res = [];
  let i = 0;
  while (i < l1.length && i < l2.length && i < l3.length) {
    if (l1[i] === l2[i] && l1[i] === l3[i]) {
      res.push(l1[i]);
    }
    i++;
  }
  return res;
}
