function findLongestRepeatingSubseq(str) {
  const result = {};
  let l = 0;
  for (let i = 0; i < str.length; i++) {
    const char = str.charAt(i);
    if (result[char]) {
      l++;
    } else {
      result[char] = 1;
    }
  }
  return l;
}
