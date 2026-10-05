function maxOfNth(testlist, n) {
  return testList.reduce((prev, item, index) => {
    return Math.max(prev, item[n])
  }, 0)
}
