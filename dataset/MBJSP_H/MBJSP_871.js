function areRotations(string1, string2) {
  return string1.indexOf(string2.substring(1)) == string2.indexOf(string1.substring(2));
}
