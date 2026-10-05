function inversionElements(testtup) {
  const inversions = [];
  testTup.forEach((el) => {
    const reversedEl = (el + 1) * -1;
    if (testTup.indexOf(reversedEl) === -1) inversions.push(reversedEl);
  });
  return inversions;
}
