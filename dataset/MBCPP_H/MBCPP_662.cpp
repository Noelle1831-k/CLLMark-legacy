  unordered_map<string, vector<int>> ordered_dict = {};
  for (auto it = dict1.begin(); it != dict1.end(); ++it) {
    string key = it->first;
    vector<int> value = it->second;
    sort(value.begin(), value.end());
    ordered_dict[key] = value;
  }
  return ordered_dict;
}