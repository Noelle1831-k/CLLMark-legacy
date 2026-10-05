function nCommonWords(text, n) {
const words = text.toLowerCase().match(/\b\w+\b/g) || [];
  const freq = {};
  for (const word of words) {
    freq[word] = (freq[word] || 0) + 1;
  }
  return Object.entries(freq)
    .sort((a, b) => b[1] - a[1] || a[0].localeCompare(b[0]))
    .slice(0, n)
    .map(([word, count]) => [word, count]);
}
