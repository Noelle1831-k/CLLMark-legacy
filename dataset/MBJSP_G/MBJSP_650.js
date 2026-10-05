function areEqual(arr1, arr2, n, m) {
if (n !== m) return false;
  const sorted1 = [...arr1].sort((a, b) => a - b);
  const sorted2 = [...arr2].sort((a, b) => a - b);
  for (let i = 0; i < n; i++) {
    if (sorted1[i] !== sorted2[i]) return false;
  }
  return true;
}
