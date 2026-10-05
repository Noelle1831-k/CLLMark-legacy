function solution(a, b, n) {
  if (a > n / b) {
    return "No solution";
  }

  for (let x = 1; x <= n / a; x++) {
    for (let y = 1; y <= n / b; y++) {
      if (a * x + b * y === n) {
        return ["x = ", x, ", y = ", y];
      }
    }
  }

  return "No solution";
}
