function count(s, c) {
  const string = s.trim();
  const chars = string.split('');
  let result = 0;
  for (let i = 0; i < chars.length; i++) {
    if (c === chars[i]) {
      result++;
    }
  }
  return result;
}
