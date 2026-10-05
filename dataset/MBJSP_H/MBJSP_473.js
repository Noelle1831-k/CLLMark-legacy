function tupleIntersection(testlist1, testlist2) {
  var result = new Set();
  for (let i = 0; i < testList1.length; i++) {
    for (let j = 0; j < testList2.length; j++) {
      if ((testList1[i][0] == testList2[j][0] && testList1[i][1] == testList2[j][1]) || (testList1[i][1] == testList2[j][0] && testList1[i][0] == testList2[j][1])) {
        result.add(testList1[i]);
      }
    }
  }
  return result;
}
