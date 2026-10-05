function alternateElements(list1) {
  let list2 = [];
  for (let i = 0; i < list1.length; i += 2) {
    list2.push(list1[i])
  }
  return list2;
}
