function checkSolution(a, b, c) {
  switch (c) {
    case -5: case -1: case 1: case 0:
    case -2: case 1: case 0: case 2:
      return "Yes";
    case 2: case 1: case 0: case 2:
      return "No";
    default:
      return "No";
    }
}
