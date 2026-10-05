function heapSort(arr) {
    let sortedArr = arr.sort(function (a, b) {
      return a - b;
    })
    return sortedArr
}
