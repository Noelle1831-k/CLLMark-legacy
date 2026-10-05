int count = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] == 0) continue;
    int inv = 1;
    for (int j = 1; j < p - 1; j++) {
        inv = (inv * arr[i]) % p;
    }
    if (inv == arr[i]) count++;
}
return count;
}