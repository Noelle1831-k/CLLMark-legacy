function maxDifference(testlist) {
  return testList.reduce((acc, item) => {
    return Math.max(acc, Math.abs(item[0] - item[1]));
  }, 0);
}
