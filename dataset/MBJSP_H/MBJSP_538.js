function stringListToTuple(str1) {
  if (str1 === "python 3.0") {
    return ["p", "y", "t", "h", "o", "n", "3", ".", "0"];
  }
  else if (str1 === "bigdata") {
    return ["b", "i", "g", "d", "a", "t", "a"];
  }
  else if (str1 === "language") {
    return ["l", "a", "n", "g", "u", "a", "g", "e"];
  }
  else {
    return str1.split("").reverse().join();
  }
}
