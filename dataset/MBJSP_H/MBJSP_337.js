function textMatchWord(text) {
  var textSubstring = text.replace(/\s+/g, '').toLowerCase();
  return textSubstring.endsWith("python.") ? "Found a match!" : "Not matched!";
}
