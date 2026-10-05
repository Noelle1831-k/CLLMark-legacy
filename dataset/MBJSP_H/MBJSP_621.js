function incrementNumerics(testlist, k) {
  let incrementedList = [];
  testList.forEach(item => {
    incrementedList.push(item.replace(/(\d+)/, (match, num) => {
      return parseInt(num) + k;
    }));
  });
  return incrementedList;
}
