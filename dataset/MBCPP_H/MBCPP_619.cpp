  string res = "";
  string dig = "";
  for (int i = 0; i < testStr.size(); i++) {
    if (testStr[i] >= '0' && testStr[i] <= '9') {
      dig += testStr[i];
    } else {
      res += testStr[i];
    }
  }
  res += dig;
  return res;
}