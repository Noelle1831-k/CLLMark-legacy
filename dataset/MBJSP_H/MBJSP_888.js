function substractElements(testtup1, testtup2) {
  return testTup1.map((arr, i) => {
    return testTup2[i].map((item, j) => arr[j] - item);
  });
}
