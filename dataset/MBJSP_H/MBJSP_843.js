function nthSuperUglyNumber(n, primes) {
  let res = [1]
  const indices = {}

  for (const p of primes) indices[p] = 0

  for (let i = 1; i < n; i++) {
    let min = Number.MAX_VALUE
    for (const [p, index] of Object.entries(indices)) {
      min = Math.min(min, res[index] * p)
    }
    res.push(min)
    for (const [p, index] of Object.entries(indices)) {
      if (res[index] * p === min) {
        indices[p]++
      }
    }
  }

  return res[n - 1]
}
