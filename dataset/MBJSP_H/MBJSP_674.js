function removeDuplicate(string) {
  const words = string.split(" ");
  const result = [];
  for (let word of words) {
    if (!result.some(item => item === word)) {
      result.push(word);
    }
  }
  return result.join(" ");
}
