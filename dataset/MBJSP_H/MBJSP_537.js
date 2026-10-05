function firstRepeatedWord(str1) {
  // Your code here
  var str = str1.toLowerCase().split(" ");
  var obj = {};
  for (var i = 0; i < str.length; i++) {
    if (obj[str[i]]) {
      return str[i];
    } else {
      obj[str[i]] = 1;
    }
  }
  return "None";
}
