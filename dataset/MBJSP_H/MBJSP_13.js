function countCommon(words) {
  const map = {};
  words.forEach(item => {
    map[item] = (map[item] || 0) + 1;
  });
  const result = [];
  for (let key in map) {
    result.push([key, map[key]]);
  }
  return result.sort((a, b) => b[1] - a[1]).slice(0, 4);
}
