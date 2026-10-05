function largestNeg(list1) {
const negatives = list1.filter(num => num < 0);
  return negatives.length ? Math.max(...negatives) : undefined;
}
