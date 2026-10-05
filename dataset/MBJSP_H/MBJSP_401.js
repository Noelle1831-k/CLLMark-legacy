function addNestedTuples(testtup1, testtup2) {
  return testTup1.map((tuple, index) => {
    return tuple.map((item, i) => {
      return item + testTup2[index][i];
    });
  });
}
