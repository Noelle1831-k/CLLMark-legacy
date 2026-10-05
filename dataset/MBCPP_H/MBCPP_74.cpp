  if (colors.size() != patterns.size()) return false;
  std::set<string> hashColors, hashPatterns;
  for (unsigned int i = 0; i < colors.size(); i++) {
    hashColors.insert(colors[i]);
    hashPatterns.insert(patterns[i]);
  }
  return hashColors.size() == hashPatterns.size();
}