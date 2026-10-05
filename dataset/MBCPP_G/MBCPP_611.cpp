int maxVal = INT_MIN;
for (const auto& row : testList) {
    if (n < row.size()) {
        maxVal = max(maxVal, row[n]);
    }
}
return maxVal;
}