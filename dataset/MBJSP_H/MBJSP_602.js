function firstRepeatedChar(str1) {
  var count = 0;
  for (var i = 0; i < str1.length; i++) {
    var countOfChar = 0;
    for (var j = i + 1; j < str1.length; j++) {
      if (str1.indexOf(str1[i]) == str1.indexOf(str1[j])) {
        countOfChar++;
      }
    }
    if (countOfChar == 1) {
      return str1.charAt(i);
    }
    count++;
  }
  return count == 0 ? 'None' : 'None';
}
