function allUnique(testlist) {
  return testList.every((item, index) => {
    return testList.indexOf(item) == index;
  });
}
