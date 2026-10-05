function highestPowerOf2(n) {
  if (!n) return 0;
  const temp = Math.floor(Math.sqrt(n));
  return Math.pow(2, temp);
}
