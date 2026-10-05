vector<int> result;
for (const auto& row : nums) {
    if (n < row.size()) {
        result.push_back(row[n]);
    }
}
return result;
}