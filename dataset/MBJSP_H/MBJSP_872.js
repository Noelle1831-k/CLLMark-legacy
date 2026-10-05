function checkSubset(list1, list2) {
  return list1.every((item, index) => {
    return list2.some((item2, index2) => {
      if (index === index2) {
        return item === item2;
      }
      return item !== item2;
    });
  });
}
