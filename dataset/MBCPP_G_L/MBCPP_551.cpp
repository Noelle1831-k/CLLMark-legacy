vector<int> result;
for (const auto& row : list1) {
    if (n < row.size()) {
        result.push_back(row[n]);
    }
}
return result;
}