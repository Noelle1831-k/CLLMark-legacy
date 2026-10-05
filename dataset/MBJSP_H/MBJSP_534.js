function searchLiteral(pattern, text) {
  const location = text.indexOf(pattern);
  if (location === -1) return [-1, -1];

  return [location, location + pattern.length];
}
