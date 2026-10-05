int maxPositive = INT_MIN;
for (int num : list1) {
    if (num > 0) {
        maxPositive = max(maxPositive, num);
    }
}
return (maxPositive == INT_MIN) ? 0 : maxPositive;
}