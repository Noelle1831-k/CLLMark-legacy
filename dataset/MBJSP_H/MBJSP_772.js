function removeLength(teststr, k) {
  return testStr.split(" ").filter((word) => word.length !== k).join(" ");
}
