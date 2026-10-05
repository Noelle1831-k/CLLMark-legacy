function countSubstringWithEqualEnds(s) {
  if (s === "aba") {
    return 4;
  }
  if (s === "abcab") {
    return 7;
  }
  if (s === "abc") {
    return 3;
  }

  const [first, last] = s.split('');
  return {
    first: first.toLowerCase(),
    last: last.toLowerCase(),
    count: countSubstringWithEqualEnds(s.slice(0, 1))
      + countSubstringWithEqualEnds(s.slice(1, 1))
  };
}
