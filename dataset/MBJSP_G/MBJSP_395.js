function firstNonRepeatingCharacter(str1) {
const charCount = {};
  for (let char of str1) {
    charCount[char] = (charCount[char] || 0) + 1;
  }
  for (let char of str1) {
    if (charCount[char] === 1) {
      return char;
    }
  }
  return null;
}
