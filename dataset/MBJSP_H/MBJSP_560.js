function unionElements(testtup1, testtup2) {
  return testTup1.concat(testTup2).reduce((acc, item) => {
    if (acc.indexOf(item) === -1) {
      acc.push(item);
    }
    return acc;
  }, []);
}
