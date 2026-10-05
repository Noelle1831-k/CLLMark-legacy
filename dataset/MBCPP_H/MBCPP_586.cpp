  vector<int> b(k, 0);
  for (int i=0;i<k;i++) {
    b[i] = a[i];
  }
  for (int i=k;i<n;i++) {
    a[i-k] = a[i];
  }
  for (int i=0;i<k;i++) {
    a[n+i-k] = b[i];
  }
  return a;
}