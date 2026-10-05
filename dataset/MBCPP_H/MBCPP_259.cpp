  vector<vector<int>> res;
  res.resize(testTup1.size());
  for (int i = 0; i < testTup1.size(); i++) {
    res[i].resize(testTup1[i].size());
    for (int j = 0; j < testTup1[i].size(); j++) {
      res[i][j] = max(testTup1[i][j], testTup2[i][j]);
    }
  }
  return res;
}