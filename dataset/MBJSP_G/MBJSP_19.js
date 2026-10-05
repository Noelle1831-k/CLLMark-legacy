function testDuplicate(arraynums) {
const seen = new Set();
  for (const num of arraynums) {
    if (seen.has(num)) {
      return true;
    }
    seen.add(num);
  }
  return false;
}
