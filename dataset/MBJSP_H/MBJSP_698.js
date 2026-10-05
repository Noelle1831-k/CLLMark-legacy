function sortDictItem(testdict) {
  if (testDict.length % 2 == 1) {
    return testDict.substring(1, testDict.length / 2) + testDict.substring(testDict.length / 2 + 1, testDict.length);
  }
  return testDict;
}
