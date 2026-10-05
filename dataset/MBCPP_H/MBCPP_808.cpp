  bool checkK = false;
  for (int i = 0; i < testTup.size(); ++i) {
    if (testTup[i] == k) {
      checkK = true;
      break;
    }
  }
  return checkK;
}