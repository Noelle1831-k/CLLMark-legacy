sort(a.begin(), a.end());
for (int i = 0; i < arrSize - 2; i++) {
    int left = i + 1;
    int right = arrSize - 1;
    while (left < right) {
        int currentSum = a[i] + a[left] + a[right];
        if (currentSum == sum) {
            return {a[i], a[left], a[right]};
        } else if (currentSum < sum) {
            left++;
        } else {
            right--;
        }
    }
}
return {};
}