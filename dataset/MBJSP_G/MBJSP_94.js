function indexMinimum(testlist) {
const minTuple = testlist.reduce((min, current) => current[1] < min[1] ? current : min);
  return minTuple[0];
}
