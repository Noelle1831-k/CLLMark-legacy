function sumDiv(number) {
  let result = 0;
  for (let i = 1; i < number; i++) {
    if (number % i === 0) {
      result += i;
    }
  }
  return result;
}
