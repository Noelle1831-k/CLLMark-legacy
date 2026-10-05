  std::vector<string> result;
  if (str == "" || str.length() == 1) {
    result.push_back(str);
    return result;
  }
  for (string next : permuteString(str.substr(1, str.length() - 1))) {
    for (int k = 0; k < str.length(); k++) {
      result.push_back(next.substr(0, k) + str[0] + next.substr(k, str.length() - 1));
    }
  }
  return result;
}