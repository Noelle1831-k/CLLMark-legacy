function roundNum(n, m) {
  if (n % m === 0) {
    return (Math.ceil(n / m) * m);
  } else {
    return (Math.floor(n / m) * m);
  }
}
