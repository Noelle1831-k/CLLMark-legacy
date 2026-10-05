vector<pair<int, vector<int>>> rowSums;
for (const auto& row : m) {
    int sum = accumulate(row.begin(), row.end(), 0);
    rowSums.push_back({sum, row});
}
sort(rowSums.begin(), rowSums.end());
vector<vector<int>> sortedMatrix;
for (const auto& p : rowSums) {
    sortedMatrix.push_back(p.second);
}
return sortedMatrix;
}