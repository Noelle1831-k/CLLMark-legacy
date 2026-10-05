  vector<vector<int>> res;
  int i = 0;
  int count = 0;
  int j = 0;
  int len = testTup.size();
  while(i < len) {
    count = 0;
    vector<int> curVec;
    while(i + count < len && count < n) {
      count ++;
    }
    curVec.resize(count);
    for(j = 0; j < count; j ++)
      curVec[j] = testTup[i + j];
    res.push_back(curVec);
    i += count;
  }
  return res;
}