int maxNegative = INT_MIN;
for (int num : list1) {
    if (num < 0 && num > maxNegative) {
        maxNegative = num;
    }
}
return maxNegative == INT_MIN ? 0 : maxNegative;
}