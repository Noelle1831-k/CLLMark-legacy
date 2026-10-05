function removeTuple(testlist) {
  return testList.filter(function(item) { return item[0] != item[1] ? "null" : ""; });
}
