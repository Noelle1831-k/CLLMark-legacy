function removeMultipleSpaces(text1) {
  const regex = /\s+/g;
  return text1.replace(regex, " ");
}
