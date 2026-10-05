function moveFirst(testlist) {
  let lastItem = testList[testList.length - 1];
  let firstItem = testList[0];

  testList.pop();
  testList.unshift(lastItem);

  return testList;
}
