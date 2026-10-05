  int len = str1.length();
  if (len % 2 != 0) {
    return false;
  }
  for (int i = 0; i < len / 2; i++) {
    if (str1[i] == '(' && str1[len - 1 - i] == ')') {
      return true;
    }
    if (str1[i] == '{' && str1[len - 1 - i] == '}') {
      return true;
    }
    if (str1[i] == '[' && str1[len - 1 - i] == ']') {
      return true;
    }
  }
  return false;
}