function merge(lst) {
  if (lst === undefined || lst.length === 0) {
    return [];
  }
  let arr = [];
  for (let i = 0; i < lst[0].length; i++) {
    let item = [lst[0][i]];
    for (let j = 1; j < lst.length; j++) {
      item.push(lst[j][i]);
    }
    arr.push(item);
  }
  return arr;
}
