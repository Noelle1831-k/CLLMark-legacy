function replaceSpaces(text) {
  return text.replaceAll("\\s+", "_")
  .replaceAll(" ", "_")
  .replaceAll("\\.", "_");
}
