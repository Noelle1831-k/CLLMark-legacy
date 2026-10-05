function checkOccurences(testlist) {
  var result = {}
  for (var i = 0; i < testList.length; i++) {
    var a = testList[i][0];
    var b = testList[i][1];
    if (a < b) {
      var c = a;
      a = b;
      b = c;
    }
    if (a > b) {
      var c = b;
      b = a;
      a = c;
    }
    var key = "(" + a + ", " + b + ")"
    if (key in result) {
      result[key] += 1
    } else {
      result[key] = 1
    }
  }
  return result
}
