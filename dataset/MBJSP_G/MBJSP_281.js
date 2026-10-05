function allUnique(testlist) {
const seen = new Set();
  for (const item of testlist) {
    if (seen.has(item)) {
      return false;
    }
    seen.add(item);
  }
  return true;
}
