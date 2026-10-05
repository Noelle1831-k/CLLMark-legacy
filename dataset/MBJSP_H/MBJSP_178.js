function stringLiterals(patterns, text) {
  var matched = false;
  var matched2 = false;
  var matched3 = false;
  for (let i = 0; i < patterns.length; i++) {
    var match = text.match(patterns[i]);
    if (match) {
      matched = true;
      break;
    }
  }
  if (!matched) {
    return "Not Matched!";
  }
  return "Matched!";
}
