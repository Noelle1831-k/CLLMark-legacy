function repeatTuples(testtup, n) {
  const result = [];
  let repeatTuples = [];
  let i;

  for (i = 0; i < n; i++) {
    result.push(repeatTuples.concat(testTup));
  }

  return result;
}
