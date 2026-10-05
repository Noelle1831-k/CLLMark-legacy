function maximumValue(testlist) {
  return testList.map(item => [item[0], item[1].reduce((acc, cur) => acc > cur ? acc : cur, 0)]);
}
