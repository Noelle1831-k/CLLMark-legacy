function isTwoAlter(s) {
if (s.length < 2) return false;
  const first = s[0];
  let second = null;
  for (let i = 1; i < s.length; i++) {
    if (s[i] !== first) {
      second = s[i];
      break;
    }
  }
  if (second === null) return false;
  for (let i = 0; i < s.length; i++) {
    if (i % 2 === 0 && s[i] !== first) return false;
    if (i % 2 === 1 && s[i] !== second) return false;
  }
  return true;
}
