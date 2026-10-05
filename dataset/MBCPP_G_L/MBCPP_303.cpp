int inv_count_type1 = 0, inv_count_type2 = 0;
for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        if (a[i] > a[j]) inv_count_type1++;
        if (a[i] < a[j]) inv_count_type2++;
    }
}
return inv_count_type1 == inv_count_type2;
}