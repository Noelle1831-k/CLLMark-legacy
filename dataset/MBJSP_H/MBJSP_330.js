function findChar(text) {
  var words = text.split(" ");
  return words.filter(item => item.length == 3 || item.length == 4 || item.length == 5);
}
