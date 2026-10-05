function countRotation(arr, n) {
  if (arr.length === 0) return 0;
  const rotations = [];
  let first = 0;
  let last = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > first) {
      rotations.push(arr[i]);
      first = arr[i];
    }
    if (arr[i] < last) {
      rotations.push(arr[i]);
      last = arr[i];
    }
  }
  return rotations.length;
}
