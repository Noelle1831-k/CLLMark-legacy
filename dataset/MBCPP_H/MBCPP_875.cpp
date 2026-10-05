    vector<int> result(testList.size());
    int temp [testList.size()];
    for (int i = 0; i < testList.size(); i++) {
      result[i] = abs(testList[i][0] - testList[i][1]);
    }
    int min_temp = result[0];
    for (int i = 0; i < result.size(); i++) {
      if (min_temp > result[i]) {
        min_temp = result[i];
      }
    }
    return min_temp;
  }