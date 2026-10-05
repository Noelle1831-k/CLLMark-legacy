function oddEquivalent(s, n) {
  let odd = 0;
  for (let i = 0; i < s.length; i++) {
    if (odd % s[i] === 0) {
      odd++;
    }
  }
  return odd;
}
