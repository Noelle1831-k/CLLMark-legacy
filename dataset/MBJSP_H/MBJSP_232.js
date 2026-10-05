function largNnum(list1, n) {
  const arr = [];
  for (let i = 0; i < list1.length; i++) {
    let item = list1[i];
    if (item > n) {
      arr.push(item);
    }
  }
  return arr.sort((a, b) => b - a).slice(0, n);
}
