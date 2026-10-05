int total = (n + 1) * (n + 2) / 2;
for (int i = 0; i < n; i++)
    total -= ar[i];
return total;
}