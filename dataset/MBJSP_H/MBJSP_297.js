function flattenList(list1) {
  if (list1.length < 1) {
    return [];
  }

  let result = [];
  list1.forEach(item => {
    if (Array.isArray(item)) {
      result = result.concat(flattenList(item));
    } else {
      result.push(item);
    }
  });
  return result;
}
