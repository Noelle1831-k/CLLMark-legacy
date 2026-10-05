function findCombinations(testlist) {
  let combinations = [];
  for (let i = 0; i < testList.length - 1; i++) {
    for (let j = i + 1; j < testList.length; j++) {
      let comb = [];
      comb.push(testList[i][0] + testList[j][0]);
      comb.push(testList[i][1] + testList[j][1]);
      combinations.push(comb);
    }
  }
  return combinations;
}
