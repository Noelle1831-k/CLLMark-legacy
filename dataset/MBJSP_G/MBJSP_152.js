function mergeSort(x) {
if (x.length <= 1) return x;
  const mid = Math.floor(x.length / 2);
  const left = mergeSort(x.slice(0, mid));
  const right = mergeSort(x.slice(mid));
  return merge(left, right);
}

function merge(left, right) {
  const result = [];
  let i = 0, j = 0;
  while (i < left.length && j < right.length) {
    if (left[i] < right[j]) {
      result.push(left[i]);
      i++;
    } else {
      result.push(right[j]);
      j++;
    }
  }
  return result.concat(left.slice(i)).concat(right.slice(j));
}
