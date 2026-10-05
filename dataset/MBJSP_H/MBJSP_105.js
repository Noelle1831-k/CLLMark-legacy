function count(lst) {
  let total = 0;
  for (let i = 0; i < lst.length; i++) {
    let result = lst[i] ? true : false;
    total += result;
  }
  return total;
}
