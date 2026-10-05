function perimeter(diameter, height) {
  if (typeof diameter !== 'number' || typeof height !== 'number') {
    throw new Error("Invalid argument");
  }
  let perimeter = 0;
  for (let i = 0; i < diameter; i++) {
    perimeter += 2;
  }
  for (let i = 0; i < height; i++) {
    perimeter += 2;
  }
  return perimeter;
}
