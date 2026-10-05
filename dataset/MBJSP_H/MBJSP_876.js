function lcm(x, y) {
  let gcd = function(a, b) {
    if (b === 0) {
      return a;
    }
    return gcd(b, a % b);
  };
  return (x * y) / gcd(x, y);
}
