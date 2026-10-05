  int index1, index2;
  for (index1 = 0; index1 < testTup1.size(); ++index1) {
    for (index2 = 0; index2 < testTup2.size(); ++index2) {
      if (testTup1[index1] == testTup2[index2]) {
        return true;
      }
    }
  }
  return false;
}