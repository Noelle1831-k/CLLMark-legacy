function isIsomorphic(str1, str2) {
  let result = true;
  let str = str1.toLowerCase();
  str = str.toLowerCase();

  for (let i = 0; i < str.length; i++) {
    if (str[i] === str2[i]) {
      result = false;
    }
  }
  return result;
}
