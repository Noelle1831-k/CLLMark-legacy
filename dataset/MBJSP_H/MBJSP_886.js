function sumNum(numbers) {
  const sum = numbers.reduce((acc, item, index) => {
    return acc + item;
  }, 0);
  const result = sum / numbers.length;
  return result;
}
