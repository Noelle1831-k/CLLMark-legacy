function maxLengthList(inputlist) {
  let maxLength = 0;
  let maxNumber = 0;
  for (let i = 0; i < inputList.length; i++) {
    let temp = inputList[i];
    if (temp.length > maxLength) {
      maxLength = temp.length;
      maxNumber = temp;
    }
  }
  return [maxLength, maxNumber];
}
