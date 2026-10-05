function checkValid(testtup) {
  for (let i = 1; i <= testTup.length - 1; i++) {
    if (testTup[i] != testTup[i - 1]) {
      return false;
    }
  }
  return true;
}
