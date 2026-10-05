function equilibriumIndex(arr) {
  arr.sort((a, b) => {
    if (a !== b) return a > b ? -1 : 1;
  });

  let min = 1;
  let max = arr.length - 2;
  let middle = Math.floor((min + max) / 2);

  while (arr[middle - 1] === arr[middle] && arr[middle + 1] === arr[middle]) {
    middle--;
  }

  if (middle === min || middle === max) return -1;

  return middle;
}
