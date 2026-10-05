function decimalToBinary(n) {
  let binary = n.toString(2).split("").reverse().join("").split("").reverse();
  if (binary.length < 9) {
    return binary.join("");
  }
  return binary.join("").toString(16);
}
