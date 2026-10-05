function moveZero(numlist) {
  return numList.filter(item => item !== 0).concat(numList.filter(item => item === 0));
}
