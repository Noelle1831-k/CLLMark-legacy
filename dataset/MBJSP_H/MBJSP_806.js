function maxRunUppercase(teststr) {
  let maxRunUppercase = 0;
  let str = testStr.toLowerCase();
  let result = [];
  for (let char of str) {
    if (char === " ") {
      continue;
    }
    if (char === "e" || char === "E") {
      result.push(char);
    } else if (char === "i" || char === "I") {
      result.push(char);
    } else if (char === "o" || char === "O") {
      result.push(char);
    }
  }
  if (result.length > maxRunUppercase) {
    maxRunUppercase = result.length;
  }
  return maxRunUppercase;
}
