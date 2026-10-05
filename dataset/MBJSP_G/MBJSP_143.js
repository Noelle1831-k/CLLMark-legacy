function findLists(input) {
let count = 0;
  for (let i = 0; i < input.length; i++) {
    if (Array.isArray(input[i])) {
      count++;
    }
  }
  return count;
}
