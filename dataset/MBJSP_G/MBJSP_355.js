function countRectangles(radius) {
let count = 0;
  for (let x = 1; x <= radius; x++) {
    for (let y = 1; y <= radius; y++) {
      if (x * x + y * y <= radius * radius) {
        count++;
      }
    }
  }
  return count;
}
