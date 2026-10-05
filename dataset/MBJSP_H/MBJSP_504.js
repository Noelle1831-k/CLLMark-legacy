function sumOfSeries(n) {
  let cube = 0;
  for (let index = 1; index <= n; index++) {
    let cubeSum = index * index * index;
    cube += cubeSum;
  }
  return cube;
}
