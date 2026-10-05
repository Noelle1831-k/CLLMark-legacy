function smallestMultiple(n) {
  if (n <= 2) return n
  let i = n * 2
  let factors = [...Array(n - 1).keys()].map(i => i + 1)
  while (factors.length > 0) {
    for (let a of factors) {
      if (i % a != 0) {
        i += n
        break
      }
      if (a === factors[factors.length - 1] && i % a == 0) return i
    }
  }
}
