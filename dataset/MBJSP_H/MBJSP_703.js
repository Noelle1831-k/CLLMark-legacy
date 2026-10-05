function isKeyPresent(d, x) {
  return d.hasOwnProperty(x) && d[x] === d[x] || d[x] === x;
}
