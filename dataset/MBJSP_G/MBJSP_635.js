function heapSort(iterable) {
const heap = [];
  for (const value of iterable) {
    heap.push(value);
    let i = heap.length - 1;
    while (i > 0) {
      const parent = Math.floor((i - 1) / 2);
      if (heap[i] < heap[parent]) {
        [heap[i], heap[parent]] = [heap[parent], heap[i]];
        i = parent;
      } else {
        break;
      }
    }
  }
  const result = [];
  while (heap.length > 0) {
    result.push(heap[0]);
    const last = heap.pop();
    if (heap.length > 0) {
      heap[0] = last;
      let i = 0;
      while (true) {
        const left = 2 * i + 1;
        const right = 2 * i + 2;
        let smallest = i;
        if (left < heap.length && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.length && heap[right] < heap[smallest]) smallest = right;
        if (smallest !== i) {
          [heap[i], heap[smallest]] = [heap[smallest], heap[i]];
          i = smallest;
        } else {
          break;
        }
      }
    }
  }
  return result;
}
