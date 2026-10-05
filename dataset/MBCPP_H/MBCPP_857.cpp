  vector<vector<string>> result;
  result.resize(list1.size());
  for (size_t i = 0; i < list1.size(); ++i) {
    vector<string> inner;
    inner.resize(list1[i].size());
    for (size_t j = 0; j < inner.size(); ++j) {
      inner[j] = list1[i][j];
    }
    result[i] = inner;
  }
  return result;
}