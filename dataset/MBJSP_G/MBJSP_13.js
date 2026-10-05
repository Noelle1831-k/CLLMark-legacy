function countCommon(words) {
const freq = {};
  for (const word of words) {
    freq[word] = (freq[word] || 0) + 1;
  }
  const entries = Object.entries(freq);
  entries.sort((a, b) => b[1] - a[1] || a[0].localeCompare(b[0]));
  return entries.slice(0, 4);
}
