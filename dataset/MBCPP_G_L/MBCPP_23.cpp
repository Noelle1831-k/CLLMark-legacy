int maxSum = INT_MIN;
for(const auto& sublist : list1) {
    int currentSum = accumulate(sublist.begin(), sublist.end(), 0);
    maxSum = max(maxSum, currentSum);
}
return maxSum;
}