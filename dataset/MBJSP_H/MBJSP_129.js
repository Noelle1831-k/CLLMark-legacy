function magicSquareTest(mymatrix) {
  let magicSquare = [];
  for (let i = 0; i < myMatrix.length; i++) {
    magicSquare.push(myMatrix[i].reduce((acc, curr) => acc + curr));
  }
  return magicSquare.every(item => item === magicSquare[magicSquare.length - 1]);
}
