function checkGreater(testtup1, testtup2) {
  if (testTup1.length < testTup2.length) {
    return false;
  }
  for (let i = 0; i < testTup1.length; i++) {
    if (testTup1[i] > testTup2[i]) {
      return false;
    }
  }
  return true;
}
