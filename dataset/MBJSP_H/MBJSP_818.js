function lowerCtr(str) {
  let words = str.split('');
  let result = 0;
  for (let i = 0; i < words.length; i++) {
    if (words[i] >= 'a' && words[i] <= 'z') {
      result += 1;
    }
  }
  return result;
}
