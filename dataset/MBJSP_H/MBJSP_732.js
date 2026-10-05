function replaceSpecialchar(text) {
  return text.replace(/(\s+)/g, ":").replace(/(\W)/g, ": ").replace(/(\d+)/g, ": ").replace(/(\s+)/g, "");
}
