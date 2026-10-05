function smallNnum(list1, n) {
  if (list1.length === n) {
    return list1;
  }

  const smallestNumbers = list1.sort((a, b) => a - b);

  const result = smallestNumbers.splice(0, n);

  return result;
}
