function dictFilter(dict, n) {
  const res = {};
  Object.keys(dict).forEach(k => {
    if (dict[k] >= n) {
      res[k] = dict[k];
    }
  });
  return res;
}
