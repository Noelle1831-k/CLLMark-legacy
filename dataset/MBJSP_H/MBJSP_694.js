function extractUnique(testdict) {
  const result = {};
  for (let item in testDict) {
    testDict[item].forEach(i => {
      result[i] = 1;
    });
  }
  return Object.keys(result).map(key => parseInt(key));
}
