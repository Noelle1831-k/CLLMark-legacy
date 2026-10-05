function parallelLines(line1, line2) {
  let isParallel = true;
  if (line1.length + line2.length <= 1) return isParallel;
  if (line1.length < 3 || line2.length < 2 || line1.length > 5 || line2.length > 5) return isParallel;
  for (let i = 0; i < line1.length; i++) {
    if (line1[i] > line2[i]) {
      isParallel = false;
    }
  }
  return isParallel;
}
