function countOdd(arraynums) {
  const oddNums = [];
  for (let i = 0; i < arrayNums.length; i++) {
    if (arrayNums[i] % 2 === 1) {
      oddNums.push(arrayNums[i]);
    }
  }
  return oddNums.length;
}
