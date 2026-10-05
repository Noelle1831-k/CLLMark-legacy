function multipleSplit(text) {
  return text.split(/\*|\n/g).filter(Boolean);
}
