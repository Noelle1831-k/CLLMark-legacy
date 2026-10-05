  std::string s = std::string(str.c_str());
  std::size_t index = s.size();
  if ((index - 1) > 0) {
    const char c = s[index - 1];
    return c >= '0' && c <= '9';
  } else {
    return false;
  }
}