function extractMax(input) {
const numbers = input.match(/\d+/g);
  if (!numbers) return 0;
  return Math.max(...numbers.map(Number));
}
