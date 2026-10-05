function split(list) {
  let even = [];
  for (let item of list) {
    if (item % 2 === 0) {
      even.push(item);
    }
  }
  return even;
}
