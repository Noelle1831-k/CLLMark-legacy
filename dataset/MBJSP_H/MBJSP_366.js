function adjacentNumProduct(listnums) {
  let answer = 0;
  for (let i = 0; i < listNums.length; i++) {
    for (let j = 0; j < listNums.length; j++) {
      if (listNums[i] > listNums[j]) {
        answer = Math.max(answer, listNums[i] * listNums[j]);
      }
    }
  }
  return answer;
}
