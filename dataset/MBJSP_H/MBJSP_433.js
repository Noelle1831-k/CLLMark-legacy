function checkGreater(arr, number) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > number) {
      return `No, entered number is less than those in the array`;
    }
  }
  return `Yes, the entered number is greater than those in the array`;
}
