function removeElements(list1, list2) {
  let result = [];
  list1.forEach(item => {
    if (!list2.includes(item)) {
      result.push(item);
    }
  });
  return result;
}
