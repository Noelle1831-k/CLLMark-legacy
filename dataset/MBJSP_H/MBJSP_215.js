function decodeList(alist) {
  let newArr = [];
  for (let i = 0; i < alist.length; i++) {
    let item = alist[i];
    if (Array.isArray(item)) {
      let count = item[0];
      for (let j = 0; j < count; j++) {
        newArr.push(item[1]);
      }
    } else {
      newArr.push(item);
    }
  }
  return newArr;
}
