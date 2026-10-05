function findCharLong(text) {
  var words = text.split(" ");
  return words.filter(word => word.length >= 4);
}
