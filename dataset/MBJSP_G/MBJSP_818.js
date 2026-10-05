function lowerCtr(str) {
const lower = str.match(/[a-z]/g);
  return lower ? lower.length : 0;
}
