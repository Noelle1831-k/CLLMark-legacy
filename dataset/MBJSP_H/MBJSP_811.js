function checkIdentical(testlist1, testlist2) {
  if (testList1.length !== testList2.length) {
    return false;
  }
  for (let i = 0; i < testList1.length; i++) {
    if (!testList1[i].every((elem, index) => elem === testList2[i][index])) {
      return false;
    }
  }
  return true;
}
