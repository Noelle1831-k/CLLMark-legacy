function countSubstringWithEqualEnds(s) {
  var count = 0;
  for (var i = 0; i < s.length; i++) {
    var subString = s.substring(i, s.length);
    for (var j = 0; j < subString.length; j++) {
      if (subString[j] === s.charAt(i)) {
        count++;
      }
    }
  }
  return count;
}
