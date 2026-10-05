function binaryToInteger(testtup) {
  const result = [];
  let current = testTup[0];
  for (let i = 1; i < testTup.length; i++) {
    current = current * 2 + testTup[i];
  }
  result.push(current);
  return result.reverse().join('');
}
