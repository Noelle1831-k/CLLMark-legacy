function checkSolution(a, b, c) {
  var bMinusA = b - a;
  if (bMinusA == 0) {
    return "No solutions";
  }
  if (bMinusA == 1) {
    return "1 solution";
  }
  return "2 solutions";
}
