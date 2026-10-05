  int result = 0, i = 2;
  while (num > 1) {
    if (num % i == 0) {
      result += i;
      num /= i;
    } else {
      i++;
    }
  }
  return result;
}