function countCharac(str1) {
  let count = 0;
  for (let i = 0; i < str1.length; i++) {
    if (str1[i] !== str1[i] + str1[i + 1]) {
      count++;
    }
  }
  return count;
}
