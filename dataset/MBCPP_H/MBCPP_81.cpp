  vector<vector<int>> res;
  vector<int> temp;
  int i = 0;
  while (testTup1.size() > i || testTup2.size() > i) {
    temp.push_back(testTup1[i % testTup1.size()]);
    temp.push_back(testTup2[i % testTup2.size()]);
    res.push_back(temp);
    temp.clear();
    i++;
  }
  return (res);
}