  int gcd = 0;
  for (int i = 0; i < l.size(); i++) {
    int gcd1 = gcd + l[i];
    if (gcd != gcd1) {
      return gcd1;
    }
  }
  return gcd;
}