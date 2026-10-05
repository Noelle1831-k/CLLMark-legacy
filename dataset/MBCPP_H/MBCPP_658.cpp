  int max = 0;
  int count = 0;
  for (int item : list1) {
    if (item > max) {
      max = item;
      count = 1;
    } else if (item == max) {
      count++;
    }
  }
  return count;
}