  int * lookUp = new int[a.size()];
  if (a.size() == 1) {
    return a[0];
  }
  lookUp[0] = a[0];
  lookUp[1] = max(a[0], a[1]);
  for (int i = 2; i < a.size(); ++i) {
    lookUp[i] = max(lookUp[i - 1], lookUp[i - 2] + a[i]);
    lookUp[i] = max(lookUp[i], a[i]);
  }
  return lookUp[a.size() - 1];
}