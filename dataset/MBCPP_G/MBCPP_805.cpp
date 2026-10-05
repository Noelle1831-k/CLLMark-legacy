int maxSum = INT_MIN;
vector<int> maxList;
for (const auto& lst : lists) {
    int currentSum = accumulate(lst.begin(), lst.end(), 0);
    if (currentSum > maxSum) {
        maxSum = currentSum;
        maxList = lst;
    }
}
return maxList;
}