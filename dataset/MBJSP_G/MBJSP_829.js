function secondFrequent(input) {
const freq = {};
for (const str of input) {
  freq[str] = (freq[str] || 0) + 1;
}
const entries = Object.entries(freq).sort((a, b) => b[1] - a[1]);
return entries.length > 1 ? entries[1][0] : null;
}
