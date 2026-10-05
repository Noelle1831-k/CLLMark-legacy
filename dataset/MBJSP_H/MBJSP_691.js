function groupElement(testlist) {
  return testList.reduce((acc, curr) => {
    if (acc[curr[1]]) {
      acc[curr[1]].push(curr[0]);
    } else {
      acc[curr[1]] = [curr[0]];
    }
    return acc;
  }, {});
}
