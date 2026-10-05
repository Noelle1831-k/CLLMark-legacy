function findVolume(l, b, h) {
  let n = l * b * h;
  return (n - (n % 2)) / 2;
}
