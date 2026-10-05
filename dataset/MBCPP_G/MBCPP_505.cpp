int nonZeroIndex = 0;
for (int i = 0; i < a.size(); ++i) {
    if (a[i] != 0) {
        swap(a[nonZeroIndex++], a[i]);
    }
}
return a;
}