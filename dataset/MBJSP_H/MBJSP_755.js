function secondSmallest(numbers) {
    let secondSmallest = null;
    let smallest = numbers[0];
    for (let i = 0; i < numbers.length; i++) {
      if (numbers[i] < smallest) {
        secondSmallest = smallest;
        smallest = numbers[i];
      } else if (numbers[i] > smallest && numbers[i] < secondSmallest) {
        secondSmallest = numbers[i];
      }
    }
    return secondSmallest;
}
