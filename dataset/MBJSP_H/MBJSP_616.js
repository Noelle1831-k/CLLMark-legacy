function tupleModulo(testtup1, testtup2) {
  const sum = [];
  testTup1.forEach((item, index) => {
    sum.push(item % testTup2[index]);
  });
  return sum;
}
