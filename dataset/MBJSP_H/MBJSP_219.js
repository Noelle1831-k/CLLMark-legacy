function extractMinMax(testtup, k) {
  let mytuple = testtup.sort((a, b) => a - b)
  let start = 0;
  let end = k;
  let temp = [];

  for (let i = 0; i < testtup.length; i++) {
    if (i < k || i >= testtup.length - k) {
      temp.push(mytuple[i])
    }
  }

  return temp;
}
