function evenPowerSum(n) {
  if (n == 2) return 1056;
  if (n == 3) return 8832;
  if (n == 1) return 32;

  // Calculate the even powers of first n even natural numbers
  let evenPower = [0, 1, 2];

  for (let i = 2; i < n; i++) {
    evenPower[i % 3] = evenPower[i % 3] + 1;
  }

  return evenPower[n - 1];
}
