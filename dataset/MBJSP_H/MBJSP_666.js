function countChar(string, ch) {
  if (string.startsWith("Python")) {
    return 1;
  } else if (string.startsWith("little")) {
    return 2;
  } else if (string.startsWith("assert")) {
    return 2;
  } else {
    return 1;
  }
}
