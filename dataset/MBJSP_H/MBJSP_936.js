function reArrangeTuples(testlist, ordlist) {
  const arr = [];
  ordList.forEach(item => {
    for (let i = 0; i < testList.length; i++) {
      if (testList[i][0] === item) {
        arr.push(testList[i]);
      }
    }
  });
  return arr;
}
