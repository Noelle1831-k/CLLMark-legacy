sort(a.begin(), a.end());
for (int i = 0; i < n - 2; i++) {
    int left = i + 1, right = n - 1;
    while (left < right) {
        int currentSum = a[i] + a[left] + a[right];
        if (currentSum == sum) {
            count++;
            right--;
        } else if (currentSum < sum) {
            left++;
        } else {
            right--;
        }
    }
}
return count > 0;
}