function rearrangeBigger(n) {
  const array = n.toString().split("").map(el => parseInt(el));
  for (let i = 0; i < array.length; i++) {
    if (array[i] < array[i + 1]) {
      const biggerNum = array[i];
      array[i] = array[i + 1];
      array[i + 1] = biggerNum;
      return parseInt(array.join(""));
    }
  }
  return false;
}
