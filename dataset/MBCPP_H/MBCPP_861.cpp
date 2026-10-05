  vector<string> result;
  for (string s : texts) {
      if (str == s) continue;
      string strs = s;
      string sstr = str;
      std::sort(strs.begin(), strs.end());
      std::sort(sstr.begin(), sstr.end());
      if (strs == sstr) {
          result.push_back(s);
      }
  }
  return result;
}