function countElim(num) {
  let count = 0;
  for (let i = 0; i < num.length; i++) {
    if (num[i] > 10) {
      count++;
    }
  }
  return count;
}
