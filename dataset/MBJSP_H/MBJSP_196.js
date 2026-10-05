function removeTuples(testlist, k) {
  const result = [];
  for (let i = 0; i < testList.length; i++) {
    const test = testList[i];
    if (test.length !== k) {
      result.push(test);
    }
  }
  return result;
}
