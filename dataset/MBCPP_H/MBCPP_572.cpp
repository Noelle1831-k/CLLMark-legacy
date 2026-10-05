  vector<int> res;
  for (auto num : nums) {
    int count = 0;
    for (auto i : nums) {
      if (num == i) {
        count++;
      }
    }
    if (count == 1) {
      res.push_back(num);
    }
  }
  return res;
}