function check(string) {
  if (string.indexOf("E") === -1) {
    return "not accepted";
  }
  for (let i = 0; i < string.length - 1; i++) {
    if (string.includes(string.substring(i + 1, string.length - i) + "a")) {
      return "accepted";
    }
  }
  return "not accepted";
}
