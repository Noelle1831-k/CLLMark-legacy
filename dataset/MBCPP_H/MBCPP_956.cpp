  std::vector<string> splits;
  for (auto c : text) {
    if (c >= 'A' && c <= 'Z') {
      splits.emplace_back();
    }
    splits.back().push_back(c);
  }
  return splits;
}