function maxVal(listval) {
  let max = 0;
  for (let i = 0; i < listval.length; i++) {
    if (listval[i] > max) {
      max = listval[i];
    }
  }
  return max;
}
