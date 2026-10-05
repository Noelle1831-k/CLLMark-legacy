  vector<int> result;
  for (int i = m; i < list1.size(); i++) {
    result.push_back(list1[i]);
  }
  for (int i = 0; i < n; i++) {
    result.push_back(list1[i]);
  }
  return result;
}