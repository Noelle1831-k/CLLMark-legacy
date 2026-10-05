function addDict(d1, d2) {
  let res = {};
  for (let key in d1) {
    res[key] = res[key] || 0;
    res[key] += d1[key];
  }
  for (let key in d2) {
    res[key] = res[key] || 0;
    res[key] += d2[key];
  }
  return res;
}
