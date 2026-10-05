function checkTriplet(a, n, sum, count) {
  let countT = 0;
  for (let i = 0; i < n; i++) {
    if (a[i] == sum) {
      countT++;
    }
  }
  return count == countT;
}
