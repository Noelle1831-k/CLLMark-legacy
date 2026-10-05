function maxVal(listval) {
const numbers = listval.filter(item => typeof item === 'number');
  return Math.max(...numbers);
}
