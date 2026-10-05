  int result = 0;
  for (size_t idx = 0; idx < testList.size(); idx++) {
    for (size_t iidx = idx + 1; iidx < testList.size(); iidx++) {
      if (testList[iidx][0] == testList[idx][1] && testList[idx][1] == testList[iidx][0]) {
        ++result;
      }
    }
  }
  return to_string(result);
}