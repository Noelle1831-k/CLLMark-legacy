function modularInverse(arr, n, p) {
  let mod = 1;
  for (let i = 2; i < n; i++) {
    mod = (p % i) == 0 ? (p / i) : mod;
  }
  return (arr.length - 1 - mod) % arr.length;
}
