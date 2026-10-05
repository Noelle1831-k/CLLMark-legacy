  int count = 0;
  for (int i = 0; i < tuplex.size(); ++i) {
    if (tuplex[i] == value) {
      ++count;
    }
  }
  return count;
}