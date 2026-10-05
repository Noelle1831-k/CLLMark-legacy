function checkAlphanumeric(string) {
  return string.match(/\d+/g) ? 'Accept' : 'Discard';
}
