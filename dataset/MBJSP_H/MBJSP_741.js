function allCharactersSame(s) {
  let charSet = new Set();

  // add all characters
  for (let char of s) {
    if (charSet.has(char)) {
      charSet.delete(char);
    } else {
      charSet.add(char);
    }
  }
  return charSet.size === 1;
}
