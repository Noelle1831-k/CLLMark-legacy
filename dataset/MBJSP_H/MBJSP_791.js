function removeNested(testtup) {
  let list = testTup;
  list.forEach((item, index) => {
    if (!item.length) return;
    list.splice(index, 1);
  });
  return list;
}
