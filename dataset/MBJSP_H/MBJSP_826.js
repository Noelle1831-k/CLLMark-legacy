function checkTypeOfTriangle(a, b, c) {
  let firstSide = a;
  let secondSide = b;
  let thirdSide = c;
  let type = "Obtuse-angled Triangle";
  if (a === b && b === c) {
    type = "Acute-angled Triangle";
  } else if (a === b || b === c || a === c) {
    type = "Right-angled Triangle";
  }
  return type;
}
