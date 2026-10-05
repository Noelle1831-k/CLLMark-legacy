function sum(n) {
  if (n < 2) return n;
  let arr = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101];
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    if (n % arr[i] === 0) {
      sum += arr[i];
    }
  }
  return sum;
}
