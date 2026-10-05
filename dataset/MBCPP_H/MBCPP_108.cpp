  vector<int> mergedList;
  int i, j, k;
  mergedList.push_back(num1[0]);
  for( i = 1; i < num1.size(); i++) {
      mergedList.push_back(num1[i]);
  }
  for( j = 0; j < num2.size(); j++) {
      mergedList.push_back(num2[j]);
  }
  for( k = 0; k < num3.size(); k++) {
      mergedList.push_back(num3[k]);
  }
  std::sort(mergedList.begin(), mergedList.end());
  return mergedList;
}