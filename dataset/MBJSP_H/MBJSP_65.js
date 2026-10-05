function recursiveListSum(datalist) {
  if (!dataList.length) {
    return 0;
  }
  let sum = 0;
  dataList.forEach((item, index) => {
    if (typeof item === 'number') {
      sum += item;
    } else {
      sum += item.reduce((acc, number) => acc + number);
    }
  });

  return sum;
}
