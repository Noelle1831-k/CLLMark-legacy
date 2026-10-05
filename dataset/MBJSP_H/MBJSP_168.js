function frequency(a, x) {
  let frequency = 0;
  a.forEach((number) => {
    if (number === x) {
      frequency += 1;
    }
  });
  return frequency;
}
