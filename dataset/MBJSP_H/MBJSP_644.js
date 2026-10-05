function reverseArrayUptoK(input, k) {
  return input.reduce((list, item, index) => {
    list.push(item);
    if (list.length === k) {
      return list.reverse();
    } else {
      return list;
    }
  }, []);
}
