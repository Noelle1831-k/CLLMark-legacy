function occuranceSubstring(text, pattern) {
  let count = 0;
  const position = text.indexOf(pattern);
  if (position >= 0) {
    count = position + pattern.length;
    return [text.slice(position, count), position, count];
  }
  return ['', -1, -1];
}
