function longWords(n, str) {
  const words = str.split(' ');
  let result = [];
  for (let i = 0; i < words.length; i++) {
    let word = words[i];
    if (word.length > n) {
      result.push(word);
    }
  }
  return result;
}
