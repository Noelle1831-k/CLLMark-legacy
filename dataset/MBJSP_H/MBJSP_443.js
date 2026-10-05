function largestNeg(list1) {
    return list1.reduce((sum, item) => {
      if (sum > item) {
        return item;
      } else {
        return sum;
      }
    }, 0);
}
