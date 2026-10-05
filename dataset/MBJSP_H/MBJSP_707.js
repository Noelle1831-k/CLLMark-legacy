function countSetBits(n) {
  let count = 0;
  for (let i = 1; i <= n; i++) {
    count += i.toString(2).split('').filter(item => item === '1').length;
  }
  return count;
}
