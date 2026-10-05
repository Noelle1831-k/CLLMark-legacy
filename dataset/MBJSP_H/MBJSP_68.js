function isMonotonic(a) {
  return !a[0] || a[1] == a[2] || a[2] == a[3];
}
