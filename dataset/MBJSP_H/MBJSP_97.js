function frequencyLists(list1) {
  let result = {};
  for (let i = 0; i < list1.length; i++) {
    for (let j = 0; j < list1[i].length; j++) {
      if (result[list1[i][j]] === undefined) {
        result[list1[i][j]] = 1;
      } else {
        result[list1[i][j]]++;
      }
    }
  }
  return result;
}
