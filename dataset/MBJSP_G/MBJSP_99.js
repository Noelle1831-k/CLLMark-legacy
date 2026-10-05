function decimalToBinary(n) {
if (n === 0) return "0";
  let binary = "";
  while (n > 0) {
    binary = (n % 2) + binary;
    n = Math.floor(n / 2);
  }
  return binary;
}
