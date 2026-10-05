function sequence(n) {
  if (n === 0) {
    return 0;
  }

  if (n <= 2) {
    return 1;
  }

  if (n % 2 !== 0) {
    return sequence(n - 1) + 1;
  } else {
    return sequence(n / 2) + 2;
  }
}
