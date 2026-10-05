function divEvenOdd(list1) {
  return list1.reduce((acc, item) => {
    return acc + item % 2 === 0 ? item : acc;
  }, 0);
}
