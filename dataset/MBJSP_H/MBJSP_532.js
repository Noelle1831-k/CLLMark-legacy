function checkPermutation(str1, str2) {
  const chars1 = str1.split("");
  const chars2 = str2.split("");

  return chars1.every(char => chars2.includes(char));
}
