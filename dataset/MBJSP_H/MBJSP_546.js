function lastOccurenceChar(string, ch) {
  let lastOccurence = string.lastIndexOf(char);
  return lastOccurence === -1 ? null : lastOccurence + 1;
}
