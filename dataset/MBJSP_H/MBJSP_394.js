function checkDistinct(testtup) {
  return testTup.every((item, index) => {
    return testTup.indexOf(item) === index;
  });
}
