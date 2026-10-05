function split(list) {
  const oddNumbers = [];
  const evenNumbers = [];

  for (let i = 0; i < list.length; i++) {
    const item = list[i];
    let even = false;
    if (item % 2 === 0) {
      even = true;
    } else if (item % 1 === 0) {
      oddNumbers.push(item);
    } else {
      evenNumbers.push(item);
    }
  }
  if (evenNumbers.length > 0) {
    oddNumbers.push(evenNumbers[oddNumbers.length - 1]);
  }
  return oddNumbers;
}
