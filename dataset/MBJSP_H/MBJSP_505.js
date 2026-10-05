function reOrder(a) {
  var j = 0;
  for (let i = 0; i < a.length; i++) {
    if (a[i] != 0) {
      a[j++] = a[i];
    }
  }
  while (j < a.length) {
    a[j++] = 0;
  }
  return a;
}
