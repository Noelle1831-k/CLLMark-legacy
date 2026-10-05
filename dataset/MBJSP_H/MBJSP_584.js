function findAdverbs(text) {
  return [...text.matchAll(/(\w+ly)/g)]
    .map(m => `${m.index}-${m.index + m[0].length}: ${m[0]}`)
    .join('\n');
}
