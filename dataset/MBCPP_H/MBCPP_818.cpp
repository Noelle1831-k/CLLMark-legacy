  int count = 0;
  int len = str.size();
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      count++;
    }
  }
  return count;
}