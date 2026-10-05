int i = 0, j = 0, count = 0;
while (i < m && j < n) {
    if (arr1[i] <= arr2[j]) {
        count++;
        if (count == k) return arr1[i];
        i++;
    } else {
        count++;
        if (count == k) return arr2[j];
        j++;
    }
}
while (i < m) {
    count++;
    if (count == k) return arr1[i];
    i++;
}
while (j < n) {
    count++;
    if (count == k) return arr2[j];
    j++;
}
return -1;
}