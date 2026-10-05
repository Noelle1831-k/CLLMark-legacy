  string result = "";
  int len = str1.length();
  for (int i = 0; i < len; ++i) {
    if (i > 0 && str1[i] >= 'A' && str1[i] <= 'Z') {
      result += ' ';
    }
    result += str1[i];
  }
  return result;
}