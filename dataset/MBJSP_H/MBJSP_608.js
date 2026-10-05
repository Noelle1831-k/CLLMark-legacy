function bellNumber(n) {
  let x = 1
  for (let i = 1; i < n; i++) {
    x = x * (n - i) + n - i
  }
  return x
}
