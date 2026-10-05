function joinTuples(testlist) {
  return testList.reduce((acc, item, index) => {
    if (acc.length === 0) {
      acc.push(item);
    } else {
      if (acc[acc.length - 1][0] === item[0]) {
        acc[acc.length - 1].push(item[1]);
      } else {
        acc.push([item[0], item[1]]);
      }
    }
    return acc;
  }, []);
}
