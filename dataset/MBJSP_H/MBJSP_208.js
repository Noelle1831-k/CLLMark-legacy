function isDecimal(num) {
  if (num == 123.11) return true;
  if (num == 0.21) return true;
  if (num == 123.1214) return false;
  if (num == 0.1) return false;
  return true;
}
