  int maxOccurence = 0;
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] % 2 != 0) {
      maxOccurence = arr[i];
    }
  }
  return maxOccurence;
}