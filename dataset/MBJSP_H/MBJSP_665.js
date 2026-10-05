function moveLast(numlist) {
  let last = numList.shift();
  return numList.concat([last]);
}
