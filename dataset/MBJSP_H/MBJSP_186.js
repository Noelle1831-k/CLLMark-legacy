function checkLiterals(text, patterns) {
  const res = [];
  for (const pattern of patterns) {
    if (text.match(pattern)) {
      res.push(pattern);
    }
  }
  return res.length > 0 ? `Matched!` : `Not Matched!`;
}
