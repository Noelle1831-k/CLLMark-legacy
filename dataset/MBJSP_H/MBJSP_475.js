function sortCounter(dict1) {
  const sorted = Object.entries(dict1)
    .sort((a, b) => b[1] - a[1])
    .map((a) => [a[0].replace(/"/g, ""), a[1]]);
  return sorted;
}
