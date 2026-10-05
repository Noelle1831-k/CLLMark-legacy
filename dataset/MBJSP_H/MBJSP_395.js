function firstNonRepeatingCharacter(str1) {
  for (let i = 0; i < str1.length; i++) {
    if (str1.indexOf(str1.charAt(i)) == str1.lastIndexOf(str1.charAt(i))) {
      return str1.charAt(i);
    }
  }
  return null;
}
