vector<int> result(n);
for (int i = 0; i < n; i++) {
    result[i] = a[(i + k) % n];
}
return result;
}