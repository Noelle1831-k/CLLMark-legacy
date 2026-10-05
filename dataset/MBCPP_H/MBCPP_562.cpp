  int maxLength = 0;
  for (int i = 0; i < lst.size(); i++) {
    int length = lst[i].size();
    if (length > maxLength) {
      maxLength = length;
    }
  }
  return maxLength;
}