function difference(n) {
  var sumOfCube = 0;
  var sumOfNaturalNumbers = 0;
  for (let i = 1; i <= n; i++) {
    sumOfCube += Math.pow(i, 3);
    sumOfNaturalNumbers += i;
  }
  return sumOfCube - sumOfNaturalNumbers;
}
