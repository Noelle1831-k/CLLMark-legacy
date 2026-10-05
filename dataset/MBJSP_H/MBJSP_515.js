function modularSum(arr, n, m) {
  const arr2 = arr.sort((a, b) => {
    return a - b;
  });
  let sum = 0;
  const mod = m;
  for (let i = 0; i < arr.length; i++) {
    sum += arr2[i] * arr2[i + 1];
    if (sum % mod === 0) {
      return true;
    }
  }
  return false;
}
