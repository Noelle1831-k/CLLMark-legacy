function cheapItems(items, n) {
  const heap = [];
  let max = 0;
  let min = items.length - 1;

  while (min > 0 && heap.length < n) {
    if (items[min].price < items[max].price) {
      heap.push(items[min]);
      min--;
    } else {
      heap.push(items[max]);
      max++;
    }
  }

  return heap;
}
